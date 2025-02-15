#pragma once

#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>

class Note : public QWidget
{
    Q_OBJECT
public:
    explicit Note(const QString &title, QWidget *parent = nullptr);

    QString getTitle() const;

public slots:
    void on_titleCheck();
    void on_titleLine(QString newTitle);

private:
    QHBoxLayout *_title_hBox;
    QVBoxLayout *_main_vBox;
    QLineEdit *_title_line;
    QTextEdit *_content_text;
    QCheckBox *_title_check;
};
