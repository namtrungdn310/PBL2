#include "EditReviewsWidget.h"
#include "ui_EditReviewsWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>
#include <QString>
#include <cmath>

EditReviewsWidget::EditReviewsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditReviewsWidget),
    currentProduct(nullptr)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("EditReviewsWidget");

    ui->tblProducts->setColumnCount(3);
    ui->tblProducts->setHorizontalHeaderLabels({"ID", "Name", "Rating"});
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed); ui->tblProducts->setColumnWidth(0, 50);
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); ui->tblProducts->setColumnWidth(2, 120);

    ui->tblProducts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblProducts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblProducts->verticalHeader()->setVisible(false);
    ui->tblProducts->setWordWrap(true);

    setupStyle();
}

EditReviewsWidget::~EditReviewsWidget() { delete ui; }

void EditReviewsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event); QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void EditReviewsWidget::refreshData() {
    ui->stackReviews->setCurrentIndex(0);
    currentProduct = nullptr;
    ui->txtReply->clear();
    loadCategories();
    on_btnFilter_clicked();
}

void EditReviewsWidget::loadCategories() {
    ui->cboCategoryFilter->clear();
    ui->cboCategoryFilter->addItem("All Categories", 0);
    for(const auto& cat : system->getCategories()) {
        ui->cboCategoryFilter->addItem(QString::fromStdString(cat.getName()), cat.getCategoryId());
    }
}

Pair<double, int> EditReviewsWidget::calculateRating(int prodId) {
    MyVector<Review> reviews = system->getReviewsForProduct(prodId);
    if (reviews.empty()) return {0.0, 0};

    double sum = 0;
    int count = 0;

    for(const auto& r : reviews) {
        if (r.getRating() > 0) {
            sum += r.getRating();
            count++;
        }
    }

    if (count == 0) return {0.0, 0};

    double avg = sum / count;
    avg = std::round(avg * 10.0) / 10.0;
    return {avg, count};
}

QString EditReviewsWidget::getStarString(int rating) {
    if (rating <= 0) return "(Staff Reply)";
    QString stars = ""; for(int i=0; i<rating; ++i) stars += "★"; return stars;
}

void EditReviewsWidget::on_btnFilter_clicked() {
    int catId = ui->cboCategoryFilter->currentData().toInt();
    string kw = ui->txtSearch->text().toStdString();

    MyVector<Product> result = system->searchProducts(catId, kw, 0, -1, SORT_DEFAULT);
    displayProducts(result);
}

void EditReviewsWidget::displayProducts(const MyVector<Product>& list) {
    ui->tblProducts->setRowCount(0);
    for(const auto& p : list) {
        int r = ui->tblProducts->rowCount();
        ui->tblProducts->insertRow(r);

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(p.getProductId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(r, 0, idItem);

        ui->tblProducts->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
        ui->tblProducts->item(r, 1)->setData(Qt::UserRole, p.getProductId());

        // Rating
        Pair<double, int> rateData = calculateRating(p.getProductId());
        QString rateStr;
        if (rateData.second > 0) {
            rateStr = QString::number(rateData.first, 'f', 1) + " ★ (" + QString::number(rateData.second) + ")";
        } else {
            rateStr = "No reviews";
        }

        QTableWidgetItem* rateItem = new QTableWidgetItem(rateStr);
        rateItem->setTextAlignment(Qt::AlignCenter);
        if(rateData.second > 0) rateItem->setForeground(QBrush(QColor(243, 156, 18)));
        else rateItem->setForeground(QBrush(QColor(149, 165, 166)));

        ui->tblProducts->setItem(r, 2, rateItem);
    }
    ui->tblProducts->resizeRowsToContents();
}

void EditReviewsWidget::on_tblProducts_cellClicked(int row, int column) {
    Q_UNUSED(column);
    int prodId = ui->tblProducts->item(row, 1)->data(Qt::UserRole).toInt();
    currentProduct = system->findProduct(prodId);

    if (currentProduct) {
        ui->stackReviews->setCurrentIndex(1);
        ui->lblProdName->setText("Reviews for: " + QString::fromStdString(currentProduct->getName()));
        loadReviewsForProduct(prodId);
        ui->txtReply->clear();
    }
}

void EditReviewsWidget::loadReviewsForProduct(int prodId) {
    QLayout* layout = ui->scrollContent->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) { delete item->widget(); delete item; }
    MyVector<Review> allReviews = system->getReviewsForProduct(prodId);

    MyVector<Review> customerReviews;
    MyVector<Review> staffReplies;

    for (const auto& r : allReviews) {
        if (r.getRating() > 0) customerReviews.push_back(r);
        else staffReplies.push_back(r);
    }

    if (customerReviews.empty()) {
        QLabel* empty = new QLabel("No reviews to manage.", ui->scrollContent);
        empty->setStyleSheet("color: #999; font-style: italic; margin-top: 30px; qproperty-alignment: AlignCenter;");
        layout->addWidget(empty);
    } else {
        for (const auto& r : customerReviews) {
            QFrame* card = new QFrame(ui->scrollContent);
            card->setStyleSheet(
                "QFrame { background: #FFFFFF; border: 1px solid #EEEEEE; border-radius: 8px; margin-bottom: 8px; }"
                "QLabel { border: none; }"
                );

            QVBoxLayout* l = new QVBoxLayout(card);
            l->setSpacing(5);
            l->setContentsMargins(15, 15, 15, 15);
            QHBoxLayout* h = new QHBoxLayout();
            QLabel* name = new QLabel(QString::fromStdString(r.getCustomerName()), card);
            name->setStyleSheet("font-weight: bold; color: #2C3E50; font-size: 14px;");

            QLabel* stars = new QLabel(getStarString(r.getRating()), card);
            stars->setStyleSheet("color: #F39C12; font-size: 12px;");

            h->addWidget(name);
            h->addSpacing(10);
            h->addWidget(stars);
            h->addStretch();
            l->addLayout(h);
            QLabel* cmt = new QLabel(QString::fromStdString(r.getComment()), card);
            cmt->setWordWrap(true);
            cmt->setStyleSheet("color: #555; font-size: 13px; margin-top: 5px; margin-bottom: 10px;");
            l->addWidget(cmt);
            QString replyPrefix = "Replying to " + QString::fromStdString(r.getCustomerName()) + ":";

            for (const auto& sr : staffReplies) {
                QString content = QString::fromStdString(sr.getComment());
                if (content.startsWith(replyPrefix)) {

                    QFrame* replyFrame = new QFrame(card);
                    replyFrame->setStyleSheet(
                        "QFrame { "
                        "   background-color: #F8F9FA; "
                        "   border: none;"
                        "   border-left: 3px solid #1976D2;"
                        "   border-radius: 0px;"
                        "   margin-top: 5px;"
                        "}"
                        );

                    QVBoxLayout* rl = new QVBoxLayout(replyFrame);
                    rl->setContentsMargins(10, 5, 5, 5);
                    QHBoxLayout* rHeader = new QHBoxLayout();
                    rHeader->setContentsMargins(0, 0, 0, 0);

                    QLabel* sName = new QLabel("Shop Response", replyFrame);
                    sName->setStyleSheet("font-weight: bold; color: #1976D2; font-size: 11px; border: none;");
                    rHeader->addWidget(sName);

                    rHeader->addStretch();

                    QPushButton* btnDelSingleReply = new QPushButton("× Delete", replyFrame);
                    btnDelSingleReply->setCursor(Qt::PointingHandCursor);
                    btnDelSingleReply->setStyleSheet(
                        "QPushButton { "
                        "   color: #9E9E9E; border: none; font-size: 10px; background: transparent;"
                        "}"
                        "QPushButton:hover { color: #E53935; font-weight: bold; }"
                        );
                    connect(btnDelSingleReply, &QPushButton::clicked, [=, this]() {
                        QMessageBox::StandardButton ask = QMessageBox::question(this, "Delete Reply",
                                                                                "Remove this reply?", QMessageBox::Yes|QMessageBox::No);
                        if (ask == QMessageBox::Yes) {
                            system->removeReview(sr.getReviewId());
                            system->saveAllData();
                            loadReviewsForProduct(currentProduct->getProductId());
                        }
                    });

                    rHeader->addWidget(btnDelSingleReply);
                    rl->addLayout(rHeader);
                    QString cleanContent = content;
                    if (content.size() > replyPrefix.size()) {
                        cleanContent = content.mid(replyPrefix.size()).trimmed();
                    }

                    QLabel* sMsg = new QLabel(cleanContent, replyFrame);
                    sMsg->setWordWrap(true);
                    sMsg->setStyleSheet("color: #444; font-size: 12px; border: none; font-style: italic;");
                    rl->addWidget(sMsg);

                    l->addWidget(replyFrame);
                }
            }
            QHBoxLayout* hBtn = new QHBoxLayout();
            hBtn->addStretch();
            QPushButton* btnReply = new QPushButton(card);
            btnReply->setText("Reply");
            btnReply->setCursor(Qt::PointingHandCursor);
            btnReply->setStyleSheet(
                "QPushButton { background: transparent; color: #1976D2; border: none; font-weight: bold; font-size: 12px; text-align: right; }"
                "QPushButton:hover { text-decoration: underline; }"
                );
            connect(btnReply, &QPushButton::clicked, [=]() {
                QString replyPrefixText = "Replying to " + QString::fromStdString(r.getCustomerName()) + ": ";
                ui->txtReply->setText(replyPrefixText);
                ui->txtReply->setFocus();
                QTextCursor cursor = ui->txtReply->textCursor();
                cursor.movePosition(QTextCursor::End);
                ui->txtReply->setTextCursor(cursor);
            });
            hBtn->addWidget(btnReply);
            QPushButton* btnDelReview = new QPushButton(card);
            btnDelReview->setText("Delete Review");
            btnDelReview->setCursor(Qt::PointingHandCursor);
            btnDelReview->setStyleSheet(
                "QPushButton { background: transparent; color: #C0392B; border: none; font-weight: bold; font-size: 12px; margin-left: 10px; }"
                "QPushButton:hover { text-decoration: underline; }"
                );
            connect(btnDelReview, &QPushButton::clicked, [=]() {
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Review",
                                                                          "Delete this review and ALL its replies?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    system->removeReview(r.getReviewId());
                    string pfix = "Replying to " + r.getCustomerName() + ":";
                    MyVector<Review> tempAll = system->getReviews();
                    for(const auto& tr : tempAll) {
                        if(tr.getProductId() == r.getProductId() && tr.getRating() == 0 && tr.getComment().find(pfix) == 0) {
                            system->removeReview(tr.getReviewId());
                        }
                    }

                    system->saveAllData();
                    loadReviewsForProduct(currentProduct->getProductId());
                }
            });
            hBtn->addWidget(btnDelReview);

            l->addLayout(hBtn);
            ui->scrollContent->layout()->addWidget(card);
        }
    }
    static_cast<QVBoxLayout*>(layout)->addStretch();
}

void EditReviewsWidget::createReviewCard(const Review& review) {
    QFrame* card = new QFrame(ui->scrollContent);
    card->setObjectName("ReviewCard");

    bool isStaff = (review.getRating() == 0);

    if (isStaff) {
        card->setStyleSheet("QFrame#ReviewCard { background: #E3F2FD; border: 1px solid #90CAF9; border-radius: 10px; }");
    } else {
        card->setStyleSheet("QFrame#ReviewCard { background: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 10px; }");
    }

    QVBoxLayout* l = new QVBoxLayout(card);

    QHBoxLayout* h = new QHBoxLayout();
    QLabel* name = new QLabel(QString::fromStdString(review.getCustomerName()), card);
    name->setStyleSheet("font-weight: bold; color: #1565C0;");

    QLabel* stars = new QLabel(getStarString(review.getRating()), card);
    stars->setStyleSheet(isStaff ? "color: #1565C0; font-style: italic;" : "color: #F39C12; font-weight: bold;");

    h->addWidget(name);
    h->addStretch();
    h->addWidget(stars);
    l->addLayout(h);

    QLabel* cmt = new QLabel(QString::fromStdString(review.getComment()), card);
    cmt->setWordWrap(true);
    cmt->setStyleSheet("color: #333; margin-top: 5px; margin-bottom: 10px;");
    l->addWidget(cmt);

    QHBoxLayout* hBtn = new QHBoxLayout();
    hBtn->addStretch();

    if (!isStaff) {
        QPushButton* btnReply = new QPushButton("Reply", card);
        btnReply->setStyleSheet("background: #FFF; border: 1px solid #1976D2; color: #1976D2; border-radius: 5px; padding: 3px 10px;");
        connect(btnReply, &QPushButton::clicked, [=]() {
            QString replyPrefix = "Replying to " + QString::fromStdString(review.getCustomerName()) + ": ";
            ui->txtReply->setText(replyPrefix);
            ui->txtReply->setFocus();
            QTextCursor cursor = ui->txtReply->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->txtReply->setTextCursor(cursor);
        });
        hBtn->addWidget(btnReply);
    }
    QPushButton* btnDel = new QPushButton("Delete", card);
    btnDel->setStyleSheet("background: #FFF; border: 1px solid #C0392B; color: #C0392B; border-radius: 5px; padding: 3px 10px;");
    connect(btnDel, &QPushButton::clicked, [=]() {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete", "Delete this review?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            system->removeReview(review.getReviewId());
            loadReviewsForProduct(currentProduct->getProductId());
            on_btnFilter_clicked();
        }
    });
    hBtn->addWidget(btnDel);

    l->addLayout(hBtn);
    ui->scrollContent->layout()->addWidget(card);
}

void EditReviewsWidget::on_btnPostReply_clicked() {
    if (!currentProduct) return;

    QString content = ui->txtReply->toPlainText().trimmed();
    if (content.isEmpty()) {
        QMessageBox::warning(this, "Empty", "Please write a reply.");
        return;
    }

    Staff* s = system->getCurrentStaff();
    string staffName = s ? s->getName() + " (Staff)" : "Shop Admin";
    int staffId = s ? s->getUserId() : 0;

    int newId = system->getNewReviewId();
    Review reply(newId, currentProduct->getProductId(), staffId, 0, content.toStdString(), staffName);

    system->addReview(reply);
    system->saveAllData();

    ui->txtReply->clear();
    loadReviewsForProduct(currentProduct->getProductId());

    QMessageBox::information(this, "Sent", "Reply posted successfully!");
}

void EditReviewsWidget::on_btnBack_clicked() { emit backSignal(); }

void EditReviewsWidget::setupStyle() {
    this->setAttribute(Qt::WA_StyledBackground, true);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333; font-family: 'Segoe UI'; }"
        "QWidget#EditReviewsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"
        "QLabel#lblTitle, QLabel#lblProdName { font-size: 20px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#lblEmpty { color: #777; font-style: italic; }"
        "QLineEdit, QTextEdit, QComboBox { background-color: #FFFFFF; border: 1px solid #DDD; border-radius: 8px; padding: 8px; color: #333; }"
        "QComboBox QAbstractItemView { background-color: #FFFFFF; color: #333; selection-background-color: #1976D2; selection-color: #FFFFFF; outline: 0; }"
        "QLineEdit:focus, QTextEdit:focus, QComboBox:focus { border: 2px solid #1976D2; }"
        "QTableWidget { background-color: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 8px; selection-background-color: #1976D2; selection-color: #FFF; outline: 0; }"
        "QTableWidget::item:selected { "
        "   background-color: #1976D2; "
        "   color: #FFFFFF; "
        "}"
        "QHeaderView::section { background-color: #F9FAFB; border: none; font-weight: bold; color: #1565C0; padding: 5px; }"
        "QGroupBox { font-weight: bold; border: 1px solid #DDD; border-radius: 8px; margin-top: 10px; padding-top: 15px; background: #FAFAFA; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #1565C0; }"
        "QScrollArea { background: transparent; border: 1px solid #DDD; border-radius: 8px; }"
        "QWidget#scrollContent { background: #FAFAFA; }"
        "QPushButton { background-color: #1976D2; color: white; border-radius: 18px; padding: 10px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1565C0; }"
        "QPushButton#btnBack { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 10px; }"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"
        "QMessageBox QLabel { "
        "   color: #FFFFFF; "
        "   font-size: 14px; "
        "   font-weight: bold; "
        "}"
        "QMessageBox QPushButton { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border-radius: 5px; "
        "   padding: 5px 15px; "
        "   min-width: 60px; "
        "}"
        "QMessageBox QPushButton:hover { "
        "   background-color: #1565C0; "
        "}"
        );
}
