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
    void onTitleCheck();
    void onTitleChange(QString newTitle);

private:
    QHBoxLayout *_titleHbox;
    QVBoxLayout *_mainVBox;
    QLineEdit *_title;
    QTextEdit *_content;
    QCheckBox *_titleCheck;
};
