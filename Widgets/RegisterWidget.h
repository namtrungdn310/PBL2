#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void registerSuccess();
    void backToStartup();

private slots:
    void on_btnConfirm_2_clicked();
    void on_btnBack_clicked();

private:
    Ui::RegisterWidget *ui;

    bool validateInputs();
    bool isValidEmail(const QString &email);
    void clearAllFields();
};

#endif
