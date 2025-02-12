#include <MainWindow.h>
#include <QMenuBar>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // INIT WIDGETS
    _notes = new QList<Note*>;
    _titleInput = new QInputDialog(this);
    _login = new Login(this);

    // FILE MENU
    _fileMenu = menuBar()->addMenu("&File");
        // New
        _newAction = new QAction("&New note", this);
        _newAction->setShortcut(QKeySequence("Ctrl+N"));
        _newAction->setIcon(QIcon("C:\\Users\\pacof\\DEV\\QT\\QtReference\\logo\\new.png"));


        _fileMenu->addAction(_newAction);
        connect(_newAction, SIGNAL(triggered(bool)), this, SLOT(openTitleDialog()));

        // Quit
        _quitAction = new QAction("&Quit", this);
        _quitAction->setShortcut(QKeySequence("Ctrl+Q"));
        _quitAction->setIcon(QIcon("C:\\Users\\pacof\\DEV\\QT\\QtReference\\logo\\quit.png"));

        _fileMenu->addAction(_quitAction);
        connect(_quitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    // EDIT MENU
    _editMenu = menuBar()->addMenu("&Edit");

    // TOOLBAR
    _fileToolBar = addToolBar("File");
    _fileToolBar->addAction(_newAction);
    _fileToolBar->addAction(_quitAction);
    _fileToolBar->addSeparator();

    _utilToolBar = addToolBar("Util");
    _utilToolBar->addWidget(_login);

    // CENTRAL AREA
    _centralArea = new QMdiArea(this);

    setCentralWidget(_centralArea);
    setWindowTitle("Notes");
}

void MainWindow::addNoteToList(Note *note)
{
    _notes->emplaceBack(note);
    _centralArea->addSubWindow(note);
    note->show();
}

void MainWindow::openTitleDialog()
{
    bool ok;
    QString title = _titleInput->getText(this, "Title", "Enter title", QLineEdit::Normal, QString(), &ok);
    if(ok && !title.isEmpty())
    {
        Note *note = new Note(title, this);
        addNoteToList(note);

        foreach(Note *n, *_notes) {
            qDebug() << n->getTitle();
        }
    }
}

