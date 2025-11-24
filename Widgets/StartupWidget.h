#ifndef STARTUPWIDGET_H
#define STARTUPWIDGET_H
#include <QStyleOption>
#include <QPainter>
#include <QWidget>

namespace Ui {
class StartupWidget;
}

class StartupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartupWidget(QWidget *parent = nullptr);
    ~StartupWidget();
    void paintEvent(QPaintEvent *event) override;

signals:
    void goToLogin(int role); //role: cus hay staff ?
    void goToRegister();

private slots:
    void on_btnCustomer_clicked();
    void on_btnStaff_clicked();
    void on_btnRegister_clicked();
    void on_btnExit_clicked();

private:
    Ui::StartupWidget *ui;
};

#endif
