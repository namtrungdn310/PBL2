#ifndef ACCOUNTSETTINGWIDGET_H
#define ACCOUNTSETTINGWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QListWidgetItem>
#include <QShowEvent>

namespace Ui { class AccountSettingWidget; }

class AccountSettingWidget : public QWidget {
    Q_OBJECT

public:
    explicit AccountSettingWidget(QWidget *parent = nullptr);
    ~AccountSettingWidget();

    void refreshData();

protected:
    void showEvent(QShowEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnUpdatePass_clicked();
    void on_btnBack_clicked();

    void on_lstStaff_itemClicked(QListWidgetItem *item);
    void on_btnAddNew_clicked();
    void on_btnSaveStaff_clicked();
    void on_btnDeleteStaff_clicked();

private:
    Ui::AccountSettingWidget *ui;
    ShopSystem* system;
    int currentEditingId;

    void setupStyle();
    void loadStaffList();
    int getNextStaffId();
};

#endif
