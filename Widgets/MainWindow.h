#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widgets/StartupWidget.h"
#include "LoginWidget.h"
#include "CustomerDashboard.h"
#include "StaffDashboard.h"
#include "RegisterWidget.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleGoToLogin(int role);
    void handleGoToRegister();
    void handleLoginSuccess();
    void handleRegisterSuccess();
    void handleBackToStartup();

private:
    Ui::MainWindow *ui;
    StartupWidget *m_startup;
    RegisterWidget *m_register;
    LoginWidget *m_login;
    CustomerDashboard *m_customerDash;
    StaffDashboard *m_staffDash;
};

#endif
