#include <Note.h>

Note::Note(const QString &title, QWidget *parent)
    : QWidget(parent)
{
    // WINDOW
    setWindowTitle(title);

    // INIT
    _main_vBox = new QVBoxLayout(this);
    _title_hBox = new QHBoxLayout(this);
    _title_check = new QCheckBox(this);
    _title_line = new QLineEdit(title, this);
        _title_line->hide();
    _content_text = new QTextEdit(this);

    // CONNECT
    connect(_title_check, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(on_titleCheck()));
    connect(_title_line, SIGNAL(textChanged(QString)), this, SLOT(on_titleLine(QString)));

    // LAYOUTS
    setLayout(_main_vBox);
        _main_vBox->addLayout(_title_hBox);
            _title_hBox->addWidget(_title_check);
            _title_hBox->addWidget(_title_line);
        _main_vBox->addWidget(_content_text);

}

void Note::on_titleCheck()
{
    _title_check->isChecked() ? _title_line->show() : _title_line->hide();
}

void Note::on_titleLine(QString newTitle)
{
    setWindowTitle(newTitle);
}

QString Note::getTitle() const
{
    return _title_line->text();
}
