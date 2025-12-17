#ifndef INTROWIDGET_H
#define INTROWIDGET_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui { class IntroWidget; }

class IntroWidget : public QWidget {
    Q_OBJECT

public:
    explicit IntroWidget(QWidget *parent = nullptr);
    ~IntroWidget();

signals:
    void enterPressed();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::IntroWidget *ui;
};

#endif
