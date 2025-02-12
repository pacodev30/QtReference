#include "QMenuBar"

QMenu::Menu(QWidget *parent)
    : QWidget{parent}
{
    QMenu *menuFichier = QMenuBar().addMenu("&Fichier");

}
