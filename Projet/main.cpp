#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include "fenetre.h"
#include<QList>
class sommet;
class Arc;
class Arete;
int ar=0;
int ac2=0;
int i=0;
QList<sommet*>File;
QList<sommet*>sommetss;
QList<Arete*>Aretess;
QList<Arc*>Arcss;
int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    fenetre projet;
    projet.show();
    app.exec();
    return 0;
}
