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

    void manageWidgets();
    void manageMenu();
    void manageToolbar();
    void manageConnect();

public slots:
    /**
     * @brief openTitleDialog
     */
    void on_noteDialog();

private:
    QMenu *_file_menu, *_edit_menu;
    QAction *_newNote_action, *_quit_action;
    QMdiArea *_central_mdi;
    QInputDialog *_note_dialog;
    QToolBar *_file_toolBar, *_util_toolBar;
    Login *_login;

    QList<Note*> *_notes;

};
