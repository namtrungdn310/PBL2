#ifndef ACCOUNTSETTINGSWIDGET_H
#define ACCOUNTSETTINGSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class AccountSettingsWidget; }

class AccountSettingsWidget : public QWidget {
    Q_OBJECT

public:
    explicit AccountSettingsWidget(QWidget *parent = nullptr);
    ~AccountSettingsWidget();

    void loadUserData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();
    void accountDeleted();
private slots:
    void on_btnConfirm_clicked();
    void on_btnDelete_clicked();
    void on_btnBack_clicked();

private:
    Ui::AccountSettingsWidget *ui;
    ShopSystem* system;

    void setupStyle();
};

#endif
