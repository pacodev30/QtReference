#include <MainWindow.h>
#include <QMenuBar>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    manageWidgets();
    manageMenu();
    manageToolbar();
    manageConnect();
}

void MainWindow::manageWidgets()
{
    _notes = new QList<Note*>;
    _note_dialog = new QInputDialog(this);
    _login = new Login(this);

    // Actions
    _newNote_action = new QAction(tr("&New note"), this);
    _newNote_action->setShortcut(QKeySequence("Ctrl+N"));
    _newNote_action->setIcon(QIcon(":icon_desktop/newFile.png"));

    _quit_action = new QAction(tr("&Quit"), this);
    _quit_action->setShortcut(QKeySequence("Ctrl+Q"));
    _quit_action->setIcon(QIcon(":icon_desktop/quit.png"));

    // Area
    _central_mdi = new QMdiArea(this);
    setCentralWidget(_central_mdi);
    setWindowTitle(tr("Dashboard"));
}

void MainWindow::manageMenu()
{
    _file_menu = menuBar()->addMenu(tr("&File"));
    _file_menu->addAction(_newNote_action);
    _file_menu->addAction(_quit_action);
    _edit_menu = menuBar()->addMenu(tr("&Edit"));
}

void MainWindow::manageToolbar()
{
    _file_toolBar = addToolBar(tr("File"));
    _file_toolBar->addAction(_newNote_action);
    _file_toolBar->addAction(_quit_action);
    _file_toolBar->addSeparator();

    _util_toolBar = addToolBar(tr("Tools"));
    _util_toolBar->addWidget(_login);
}

void MainWindow::manageConnect()
{
    connect(_newNote_action, SIGNAL(triggered(bool)), this, SLOT(on_noteDialog()));
    connect(_quit_action, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

// SLOTS
void MainWindow::on_noteDialog()
{
    bool ok;
    QString title = _note_dialog->getText(this, "Title", "Enter title", QLineEdit::Normal, QString(), &ok);
    if(ok && !title.isEmpty())
    {
        Note *note = new Note(title, this);

        _notes->emplaceBack(note);
        _central_mdi->addSubWindow(note);
        note->show();
    }
}

