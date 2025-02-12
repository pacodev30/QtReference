#include <Note.h>

Note::Note(const QString &title, QWidget *parent)
    : QWidget(parent)
{
    // WINDOW
    setWindowTitle(title);

    // INIT
    _mainVBox = new QVBoxLayout(this);
    _titleHbox = new QHBoxLayout(this);
    _titleCheck = new QCheckBox(this);
    _title = new QLineEdit(title, this);
        _title->hide();
    _content = new QTextEdit(this);

    // CONNECT
    connect(_titleCheck, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(onTitleCheck()));
    connect(_title, SIGNAL(textChanged(QString)), this, SLOT(onTitleChange(QString)));

    // LAYOUTS
    setLayout(_mainVBox);
        _mainVBox->addLayout(_titleHbox);
            _titleHbox->addWidget(_titleCheck);
            _titleHbox->addWidget(_title);
        _mainVBox->addWidget(_content);

}

void Note::onTitleCheck()
{
    _titleCheck->isChecked() ? _title->show() : _title->hide();
}

void Note::onTitleChange(QString newTitle)
{
    setWindowTitle(newTitle);
}

QString Note::getTitle() const
{
    return _title->text();
}
