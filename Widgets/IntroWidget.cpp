#include "IntroWidget.h"
#include "ui_IntroWidget.h"
#include <QPixmap>

IntroWidget::IntroWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroWidget)
{
    ui->setupUi(this);
    QPixmap logo(":/assets/logo_it.png");
    if (!logo.isNull()) {
        ui->lblLogo->setPixmap(logo.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->lblLogo->setText("[LOGO KHOA CNTT]");
    }
}

IntroWidget::~IntroWidget() {
    delete ui;
}

void IntroWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit enterPressed();
    } else {
        QWidget::keyPressEvent(event);
    }
}
