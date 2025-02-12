#include <LoginForm.h>

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
{
    _loginDialog = new QDialog(this);
        _form = new QFormLayout(this);
            _pseudoLine = new QLineEdit(this);
            _passwordLine = new QLineEdit(this);
            _submitBtn = new QPushButton("Submit", this);

            // ALERT
            _pseudoAlert = new QLabel("Pseudo empty", this);
            _pseudoAlert->setStyleSheet("QLabel {color : brown;}");
            QObject::connect(_pseudoLine, SIGNAL(textChanged(QString)), _pseudoAlert, SLOT(hide()));

            _passwordAlert = new QLabel("Password empty", this);
            _passwordAlert->setStyleSheet("QLabel {color : brown;}");
            QObject::connect(_passwordLine, SIGNAL(textChanged(QString)), _passwordAlert, SLOT(hide()));

            // ADD
            _form->addRow("Pseudo : ", _pseudoLine);
            _form->addWidget(_pseudoAlert);
            _form->addRow("Password : ", _passwordLine);
            _form->addWidget(_passwordAlert);
            _form->addWidget(_submitBtn);

            QObject::connect(_submitBtn, SIGNAL(clicked(bool)), this, SLOT(submit()));
    _loginDialog->setLayout(_form);
}

// GETTERS
QDialog *LoginForm::loginDialog() const
{
    return _loginDialog;
}

QString LoginForm::pseudoEntry() const
{
    return _pseudoEntry;
}

// SLOTS
void LoginForm::submit()
{
    if(!_pseudoLine->text().isEmpty())
        _pseudoEntry = _pseudoLine->text();

    if(!_pseudoLine->text().isEmpty() && !_passwordLine->text().isEmpty())
        _loginDialog->close();
}



