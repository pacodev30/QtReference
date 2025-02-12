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

    QDialog* loginDialog() const;
    QString pseudoEntry() const;

public slots:
    void submit();

private:
    QDialog *_loginDialog;
    QFormLayout *_form;

    QLineEdit *_pseudoLine, *_passwordLine;
    QPushButton *_loginBtn, *_submitBtn;

    QString _pseudoEntry;
    QLabel *_pseudoAlert, *_passwordAlert;

};
