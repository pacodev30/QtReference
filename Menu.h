#pragma once

#include <QMenu>
#include <QMenuBar>

class Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

private:
    QMenu *_fileMenu;
};
