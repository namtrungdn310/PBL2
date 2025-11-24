#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui { class LoginWidget; }

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    void setRole(int role);
    void paintEvent(QPaintEvent *event) override;

signals:
    void loginSuccess();
    void backToStartup();

private slots:
    void on_btnConfirm_clicked();
    void on_btnBack_clicked();
    void on_btnTogglePass_toggled(bool checked);

private:
    Ui::LoginWidget *ui;
    int currentRole;
};

#endif
