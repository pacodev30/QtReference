#pragma once

#include <QWidget>
#include <LoginForm.h>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>

class Login : public QWidget
{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

public slots:
    void openLoginForm();
    void logout();

private:
    QHBoxLayout *_loginBox;
    LoginForm *_loginForm;
    QPushButton *_loginBtn, *_logOutBtn;

    QString _pseudo;
};
