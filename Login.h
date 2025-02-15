#pragma once

#include <QWidget>
#include <LoginForm.h>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>

class Login : public QWidget
{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

    void initWidgets();
    void manageLayers();
    void manageConnects();

public slots:
    void onLoginBtn();
    void onLogoutBtn();

private:
    QHBoxLayout *_main_hBox;
    LoginForm *_login_form;
    QPushButton *_login_btn, *_logOut_btn;
    QLabel *_pseudo_label;
};
