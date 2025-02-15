#include <Login.h>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(250, 50);

    initWidgets();
    manageLayers();
    manageConnects();
}

void Login::initWidgets()
{
    _pseudo_label = new QLabel(this);
    _pseudo_label->setVisible(false);

    _login_btn = new QPushButton(this);
        _login_btn->move(20, 20);
        _login_btn->setCursor(Qt::PointingHandCursor);
        _login_btn->setToolTip("Login");
        _login_btn->setIcon(QIcon(":icon_desktop/login.png"));

    _logOut_btn = new QPushButton(this);
        _logOut_btn->setVisible(false);
        _logOut_btn->setIcon(QIcon(":icon_desktop/logout.png"));
        _logOut_btn->setToolTip("Logout");
        _logOut_btn->setVisible(false);
}

void Login::manageLayers()
{
    _login_form = new LoginForm(this);
        _main_hBox = new QHBoxLayout(this);
        _main_hBox->addWidget(_pseudo_label);
        _main_hBox->addWidget(_login_btn);
        _main_hBox->addWidget(_logOut_btn);
    setLayout(_main_hBox);
}

void Login::manageConnects()
{
    connect(_login_btn, SIGNAL(released()), this, SLOT(onLoginBtn()));
    connect(_logOut_btn, SIGNAL(released()), this, SLOT(onLogoutBtn()));
}

// SLOTS
void Login::onLoginBtn()
{

        _login_form->onLoginDialog()->exec();
        _pseudo_label->setText(_login_form->onPseudoEntry());

        if(!_login_form->onPseudoEntry().isEmpty())
        {
            _pseudo_label->setVisible(true);
            _login_btn->setVisible(false);
            _logOut_btn->setVisible(true);
        }


}

void Login::onLogoutBtn()
{
    _pseudo_label->setVisible(false);
    _login_btn->setVisible(true);
    _logOut_btn->setVisible(false);
}



