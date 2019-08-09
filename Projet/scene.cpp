#include "scene.h"

SCENE::SCENE()
{
    ac2=0;
    art=0;
    s=false;
    x=false;
    y=false;
    z=false;
}

void SCENE::mousePressEvent(QGraphicsSceneMouseEvent*event){
    if(x){
   sommet *a=new sommet();

   a->setPos(event->scenePos());
    sommetss.push_back(a);
   addItem(a);
   a->setZValue(2);
   i++;
    }
    if(y){
         art = new QGraphicsLineItem(QLineF(event->scenePos(),
                                           event->scenePos()));
               art->setPen(QPen(Qt::black, 2));
               addItem(art);
     }
   if(z){
        ac = new QGraphicsLineItem(QLineF(event->scenePos(),
                                          event->scenePos()));
              ac->setPen(QPen(Qt::black, 2));
              addItem(ac);
    }
 QGraphicsScene::mousePressEvent(event);
}

void SCENE::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if( art!= 0 && y==true){
        QLineF newLine(art->line().p1(), event->scenePos());
        art->setLine(newLine);
    }

    else if ( ac!= 0 && z==true){
        QLineF newLine(ac->line().p1(), event->scenePos());
        ac->setLine(newLine);
    }

   else if(s)
        QGraphicsScene::mouseMoveEvent(event);
}

void SCENE::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (art != 0 && y==true) {
       sommets_debut = items(art->line().p1());
       sommets_fin = items(art->line().p2());
        if (sommets_fin.count() && ( sommets_fin.first() == art || sommets_debut.first() == art)){
            sommets_fin.removeFirst();
            sommets_debut.removeFirst();
        }
             removeItem(art);
             delete art;
         if (sommets_debut.count() >0 && sommets_fin.count() > 0 && sommets_debut.first()->type() ==sommet::Type &&
                 sommets_fin.first()->type() == sommet::Type && sommets_debut.first() != sommets_fin.first()) {
               debut = qgraphicsitem_cast<sommet *>(sommets_debut.first());
               fin = qgraphicsitem_cast<sommet*>(sommets_fin.first());
            Arete *art1= new Arete(debut,fin);
            ar++;
            debut->addArete(art1);
            fin->addArete(art1);
            art1->setZValue(-10.0);
            addItem(art1);
            art1->updatePosition();
            Aretess.push_back(art1);
   }
  }
    else if (ac != 0 && z==true) {
         sommets_debut  = items(ac->line().p1());
         sommets_fin = items(ac->line().p2());
        if (sommets_fin.count() && ( sommets_fin.first() == ac || sommets_debut.first() == ac)){
            sommets_fin.removeFirst();
            sommets_debut.removeFirst();}
             removeItem(ac);
             delete ac;

         if (sommets_debut.count() >0 && sommets_fin.count() > 0 && sommets_debut.first()->type() ==sommet::Type &&
                 sommets_fin.first()->type() == sommet::Type && sommets_debut.first() != sommets_fin.first()) {
           debut = qgraphicsitem_cast<sommet *>(sommets_debut.first());
           fin = qgraphicsitem_cast<sommet*>(sommets_fin.first());
            Arc *arc1= new Arc(debut,fin);
            ac2++;

            debut->addArc(arc1);
            fin->addArc(arc1);
            arc1->setZValue(-10.0);
            addItem(arc1);
            arc1->updatePosition();
            Arcss.push_back(arc1);

   }
  }
    art=0;
    ac2 = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}
