#include <LoginForm.h>

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
{
    _login_dialog = new QDialog(this);
        _form = new QFormLayout(this);
            _pseudo_line = new QLineEdit(this);
            _password_line = new QLineEdit(this);
            _submit_btn = new QPushButton("Submit", this);

            // ALERT
            _pseudo_alert = new QLabel("Pseudo empty", this);
            _pseudo_alert->setStyleSheet("QLabel {color : brown;}");
            QObject::connect(_pseudo_line, SIGNAL(textChanged(QString)), _pseudo_alert, SLOT(hide()));

            _password_alert = new QLabel("Password empty", this);
            _password_alert->setStyleSheet("QLabel {color : brown;}");
            QObject::connect(_password_line, SIGNAL(textChanged(QString)), _password_alert, SLOT(hide()));

            // ADD
            _form->addRow("Pseudo : ", _pseudo_line);
            _form->addWidget(_pseudo_alert);
            _form->addRow("Password : ", _password_line);
            _form->addWidget(_password_alert);
            _form->addWidget(_submit_btn);

            QObject::connect(_submit_btn, SIGNAL(clicked(bool)), this, SLOT(submit()));
    _login_dialog->setLayout(_form);
}

// GETTERS
QDialog *LoginForm::onLoginDialog() const
{
    return _login_dialog;
}

QString LoginForm::onPseudoEntry() const
{
    return _pseudo_entry;
}

// SLOTS
void LoginForm::submit()
{
    if(!_pseudo_line->text().isEmpty())
        _pseudo_entry = _pseudo_line->text();

    if(!_pseudo_line->text().isEmpty() && !_password_line->text().isEmpty())
        _login_dialog->close();
}



