#ifndef SCENE_H
#define SCENE_H
#include "sommet.h"
#include "Arete.h"
#include "Arc.h"
#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>

extern QList<sommet*>sommetss;
extern QList<Arete*>Aretess;
extern QList<Arc*>Arcss;
extern QList<sommet*>File;
extern int TG[100][100];
extern int i;
extern int ar;
extern int ac2;
class SCENE:public QGraphicsScene
{
public:
    SCENE();
     friend void raffraichirlestableaux();
    bool x=false;
    bool y=false;
    bool z=false;
    bool s=false;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;
private :
  QGraphicsLineItem *ac;
  QGraphicsLineItem *art;
  sommet *debut;
  sommet *fin;
  QList<QGraphicsItem*> sommets_debut;
   QList<QGraphicsItem *> sommets_fin;
};
#endif // SCENE_H
