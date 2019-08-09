#include "sommet.h"
#include "Arc.h"
#include "Arete.h"

sommet::sommet()
{
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
//*********
void sommet::setmarquer(bool k){

    marquer=k;
}
bool sommet::getmarquer(){
    return marquer;
}

int sommet:: nombre(){
    return j;
}
//************
void sommet::removeArc(Arc *arc)
{
    int index = arcs.indexOf(arc);
    if (index != -1)
        arcs.removeAt(index);
}

void sommet::removeArcs()
{
    foreach (Arc *arc, arcs) {
        arc->sommet_deb()->removeArc(arc);
        arc->sommet_f()->removeArc(arc);
        scene()->removeItem(arc);
        delete arc;
    }
}

void sommet::addArc(Arc *arc)
{
   arcs.append(arc);
   arc->updatePosition();
}

void sommet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    painter->setBrush(Qt::yellow);
   painter->drawEllipse(-20,-20,40,40);

   painter->drawText(this->boundingRect(),Qt::AlignCenter,QString::number(j));
   if (isSelected()) {
      painter->setPen(QPen(Qt::black,2,Qt::DashLine));
      painter->drawEllipse(-20,-20,40,40);
      painter->drawText(this->boundingRect(),Qt::AlignCenter,QString::number(j));
   }
}

QRectF sommet::boundingRect()const{
    return QRectF(-22,-22,45,45);
}

QVariant sommet::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange) {
        foreach (Arc *arc, arcs) {
            arc->updatePosition();
        }
        foreach (Arete *art, aretes) {
            art->updatePosition();
        }
    }
    return value;
}


void sommet::addArete(Arete *art)
{
   aretes.append(art);
   art->updatePosition();
}

void sommet::removeArete(Arete *art)
{
    int index = aretes.indexOf(art);
    if (index != -1)
        aretes.removeAt(index);
}

void sommet::removeAretes()
{
    foreach (Arete *art, aretes) {
        art->sommet_deb()->removeArete(art);
        art->sommet_f()->removeArete(art);
        scene()->removeItem(art);
        delete art;
    }
}
