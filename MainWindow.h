#pragma once

#include <QMainWindow>
#include <QMdiArea>
#include <QAction>
#include <QList>
#include <Note.h>
#include <QInputDialog>
#include <QToolBar>
#include <Login.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    /**
     * @brief addNoteToList
     * @param note
     */
    void addNoteToList(Note *note);

    /**
     * @brief openTitleDialog
     */
    void openTitleDialog();

private:
    QMenu *_fileMenu, *_editMenu;
    QAction *_newAction, *_quitAction;
    QMdiArea *_centralArea;
    QInputDialog *_titleInput;
    QToolBar *_fileToolBar, *_utilToolBar;
    Login *_login;

    QList<Note*> *_notes;

};
