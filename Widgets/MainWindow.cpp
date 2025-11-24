#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "StartupWidget.h"
#include "LoginWidget.h"
#include "RegisterWidget.h"
#include "CustomerDashboard.h"
#include "StaffDashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1024, 768);

    while (ui->mainStack->count() > 0) {
        QWidget* w = ui->mainStack->widget(0);
        ui->mainStack->removeWidget(w);
        delete w;
    }

    m_startup = new StartupWidget(this);
    m_login = new LoginWidget(this);
    m_register = new RegisterWidget(this);
    m_customerDash = new CustomerDashboard(this);
    m_staffDash = new StaffDashboard(this);

    //thêm phần tử vào stack chính
    ui->mainStack->addWidget(m_startup);      //idx 0
    ui->mainStack->addWidget(m_login);        //idx 1
    ui->mainStack->addWidget(m_register);     //idx 2
    ui->mainStack->addWidget(m_customerDash); //idx 3
    ui->mainStack->addWidget(m_staffDash); //idx 4

    setCentralWidget(ui->mainStack);

    ui->mainStack->setCurrentWidget(m_startup); //luôn hiển thị startup đầu tiên

    //tín hiệu chuyển đổi qua lại
    connect(m_startup, &StartupWidget::goToLogin, this, &MainWindow::handleGoToLogin);
    connect(m_startup, &StartupWidget::goToRegister, this, &MainWindow::handleGoToRegister);

    connect(m_login, &LoginWidget::loginSuccess, this, &MainWindow::handleLoginSuccess);
    connect(m_login, &LoginWidget::backToStartup, this, &MainWindow::handleBackToStartup);

    connect(m_register, &RegisterWidget::registerSuccess, this, &MainWindow::handleRegisterSuccess);
    connect(m_register, &RegisterWidget::backToStartup, this, &MainWindow::handleBackToStartup);

    connect(m_customerDash, &CustomerDashboard::logoutSignal, this, &MainWindow::handleBackToStartup);
    connect(m_staffDash, &StaffDashboard::logoutSignal, this, &MainWindow::handleBackToStartup);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleGoToLogin(int role)
{
    if(m_login) {
        m_login->setRole(role);
    }
    ui->mainStack->setCurrentIndex(1);
}

void MainWindow::handleGoToRegister()
{
    ui->mainStack->setCurrentIndex(2);
}


void MainWindow::handleRegisterSuccess()
{
    ui->mainStack->setCurrentIndex(0);
}

void MainWindow::handleBackToStartup()
{
    ui->mainStack->setCurrentIndex(0);
}

void MainWindow::handleLoginSuccess()
{
    ShopSystem* system = ShopSystem::getInstance();

    if (system->getCurrentCustomer() != nullptr) {
        m_customerDash->refreshAccountInfo();
        ui->mainStack->setCurrentIndex(3);
    }
    else if (system->getCurrentStaff() != nullptr) {
        m_staffDash->refreshAccountInfo();
        ui->mainStack->setCurrentIndex(4);
    }
}
