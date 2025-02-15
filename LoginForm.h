#pragma once
#include <QWidget>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QMetaEnum>

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    LoginForm(QWidget *parent = nullptr);

    QDialog* onLoginDialog() const;
    QString onPseudoEntry() const;

public slots:
    void submit();

private:
    QDialog *_login_dialog;
    QFormLayout *_form;

    QLineEdit *_pseudo_line, *_password_line;
    QPushButton *_login_btn, *_submit_btn;

    QString _pseudo_entry;
    QLabel *_pseudo_alert, *_password_alert;

};
