#include <Login.h>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    // WINDOW
    setFixedSize(250, 50);

    // FORM BUTTONS
    _loginBtn = new QPushButton("Login", this);
    _loginBtn->move(20, 20);
    _loginBtn->setCursor(Qt::PointingHandCursor);
    QObject::connect(_loginBtn, SIGNAL(clicked(bool)), this, SLOT(openLoginForm()));

    _logOutBtn = new QPushButton(this);
    _logOutBtn->setIcon(QIcon("C:\\Users\\pacof\\DEV\\QT\\QtReference\\logo\\logout.png"));
    _logOutBtn->setToolTip("Logout");
    _logOutBtn->setVisible(false);
    QObject::connect(_logOutBtn, SIGNAL(released()), this, SLOT(logout()));

    // LAYERS
    _loginForm = new LoginForm(this);
    _loginBox = new QHBoxLayout(this);
        _loginBox->addWidget(_loginBtn);
        _loginBox->addWidget(_logOutBtn);
        setLayout(_loginBox);
}

// SLOTS
void Login::openLoginForm()
{
    _loginForm->loginDialog()->exec();
    _pseudo = _loginForm->pseudoEntry();
    _loginBtn->setText(_loginForm->pseudoEntry());
    _logOutBtn->setVisible(true);
}

void Login::logout()
{
    _loginBtn->setText("Login");
    _logOutBtn->setVisible(false);
}


