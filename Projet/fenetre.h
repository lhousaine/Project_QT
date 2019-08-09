#ifndef FENETRE_H
#define FENETRE_H
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGroupBox>
#include <QComboBox>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QSpinBox>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QQueue>
#include "scene.h"
class QPixmap;
extern QList<sommet*>File;
extern QList<sommet*>sommetss;
extern QList<Arete*>Aretess;
extern QList<Arc*>Arcss;
extern int ar;
extern int ac2;

class fenetre : public QMainWindow{
    Q_OBJECT
public :
    fenetre();
    void menu();
    void toolbar();
    void graphboutton();
    void algolayout();
    void scene();
    void newfile();
    int nb(int n);
    friend void generergraphe();
    bool z2=false;
    bool y2=false;
    //les fonctions:
    friend void initialisertableaux(int);//friend??????
    void raffraichirlestableaux();
         //flot max:
   void chaineameliorante();
   int flotmax();
   void initialiser_Lij();
   int flotmax_coutMin(sommet*,sommet*);
   bool existancechaineameliorante(sommet *s,sommet *t);
   int nbrefils(sommet*);
          //flot max a cout minimum:
     sommet*getsource();
     sommet*getpuits();
private:
     //tarik algo********
     int TG[100][100];
     int F[100][100];
     int C[100][100];
     int TGrp[100][100];
     int TGrm[100][100];
     float Crp[100][100];
     float Crm[100][100];
     float y[100];
     float cout[100][100];
     float Lij[100][100];
     //************
     int indicealgo;
     int nbresommets;
     int nbrearetes;
     int nbrearcs;
    //*********
    QComboBox *flotbox= new QComboBox;
    QSpinBox *source=new QSpinBox;
    QSpinBox *puits=new QSpinBox;
    QPushButton *ggraph=new QPushButton("graphe aleatoire");
    QPushButton *nbrar=new QPushButton("valeur");
    QPushButton *cout1=new QPushButton("cout");
    //********
    QMenu *fichier;
    QMenu *aide;
    QMenu *propos;

    QAction *nouveau;
    QAction *ouvrir;
    QAction *enregistrer;
    QAction *enregistrer_sous;
    QAction *quitter;

    QAction *b_aide;
    QAction *about;

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vgroup = new QVBoxLayout;
    QVBoxLayout *vgroup2 = new QVBoxLayout;
    QVBoxLayout *vgroup3 = new QVBoxLayout;
    //**********************************
    QGroupBox *groupbox = new QGroupBox(tr("Dessine ton Graphe"));
    QGroupBox *groupbox2 = new QGroupBox(tr("Algorithme"));
    QGroupBox *groupbox3 = new QGroupBox(tr("Scene"));
    QPushButton *b_sommet = new QPushButton();
    QPushButton *b_arete = new QPushButton();
    QPushButton *b_arc = new QPushButton();
    QPushButton *b_supprimer = new QPushButton();
    QPushButton *b_select = new QPushButton();
    QComboBox *sceneScaleCombo= new QComboBox;
    QStringList scales;
    QWidget *centre = new QWidget;
    //***********************************
    QPushButton *b_algorithme = new QPushButton("algorithmes");
    QPushButton *b_go = new QPushButton("Appliquer");
    QPushButton *b_source = new QPushButton("source");
    //***********************************
    SCENE *sene = new SCENE;   //notre scene ******************************//
    QGraphicsView *view = new QGraphicsView(this);
    //*********variables
    QString file_path;
    //read file
public slots:
    void slotSommet();
    void slotArrete();
    void slotArc();
    void slotnewfile();
    void slotsave();
    void slotsave_as();
    void slotopen();
    void slotquit();
    void slotAbout();
    void slotAide();
    void sceneScaleChanged(const QString &scale);
    void deleteItem();
    void ItemSelected();
    void nbresometare();
    void slotnbrar();
    void slotcout();
    //algo******************************************************
    //***************************************************************
    void recupererindicealgo();
    void appliqueralgo();
     //*******************************************************************
     //*******************************************************************
    //*****fct ami*******
    void generergraphe()
    {
        sene->clear();
                 for(int k=0;k<this->nbresommets;k++){
                 int x = QRandomGenerator::global()->bounded(600);
                 int y = QRandomGenerator::global()->bounded(500);
                 sommet*a=new sommet();
                 sommetss.push_back(a);
                 a->setPos(QPointF(x,y));
                 sene->addItem(a);
                 i++;
                 }
                for(int k=0;k<this->nbrearcs;k++){
                    int i = QRandomGenerator::global()->bounded(nbresommets);
                    int j= QRandomGenerator::global()->bounded(nbresommets);
                   int n= QRandomGenerator::global()->bounded(100);//lhouss
                    Arc*ac=new Arc(sommetss[i],sommetss[j]);
                    Arcss.push_back(ac);
                    sommetss[i]->addArc(ac);
                    sommetss[j]->addArc(ac);
                    ac->setZValue(-10.0);
                    ac->setcapacite(n);//lhouss
                    sene->addItem(ac);
                    ac->updatePosition();
         }
                for(int k=0;k<this->nbrearetes;k++){
                    int i = QRandomGenerator::global()->bounded(nbresommets);
                    int j= QRandomGenerator::global()->bounded(nbresommets);
                    int n= QRandomGenerator::global()->bounded(100);//lhouss
                    Arete*ac=new Arete(sommetss[i],sommetss[j]);
                    Aretess.push_back(ac);
                    sommetss[i]->addArete(ac);
                    sommetss[j]->addArete(ac);
                    ac->setZValue(-10.0);
                    ac->setcapacite(n);//lhouss
                    sene->addItem(ac);
                    ac->updatePosition();
         }
    }
    void initialisertableaux(int d){
   if(d==1){   for(int i=0;i<100;i++){
          for(int j=0;j<100;j++){
               TG[i][j]=0;
               F[i][j]=0;
               C[i][j]=0;
               TGrp[i][j]=0;
               TGrm[i][j]=0;
               Crp[i][j]=0;
               Crm[i][j]=0;
          }
      }
}
   if(d==2){
       for(int i=0;i<100;i++){
           for(int j=0;j<100;j++){
            TG[i][j]=0;
            F[i][j]=0;
            C[i][j]=0;
            TGrp[i][j]=0;
            TGrm[i][j]=0;
            Crp[i][j]=0;
            Crm[i][j]=0;
            cout[i][j]=0;
            Lij[i][j]=0;
           }
       }
    for(int i=0;i<Arcss.length();i++){
        Arcss[i]->setflot(0);
    }
    for(int i=0;i<Aretess.length();i++){
        Aretess[i]->setflot1(0);
         Aretess[i]->setflot2(0);
    }
    for(int i=0;i<Arcss.length();i++){
        Arcss[i]->setcout(0);
    }
   }
   }
};

#endif // FENETRE_H
