
#include "Arete.h"

Arete::Arete(sommet *source, sommet *dest, QGraphicsItem *parent): QGraphicsLineItem(parent)

{
   sommet_debut = source;
   sommet_fin = dest;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = Qt::black;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

QRectF Arete::boundingRect() const
{
  if(line().p2().x() - line().p1().x()< 400 &&line().p2().x() - line().p1().x()>10 &&line().p2().y() - line().p1().y()<0){
   return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
              line().p2().y() - line().p1().y())).normalized()
              .adjusted(-20, -20, 30, 40);}

 if(line().p2().y() - line().p1().y()>140 &&line().p2().x() - line().p1().x()< -12){
  return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
             line().p2().y() - line().p1().y())).normalized()
             .adjusted(-20, -20, 30, 40);}
if(line().p2().x() - line().p1().x()>-120 && line().p2().x() - line().p1().x()< -15 && line().p2().y() - line().p1().y()>0)
{

 return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
              line().p2().y() - line().p1().y())).normalized()
             .adjusted(-20, -20, 30, 40);
}
 else{ return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
             line().p2().y() - line().p1().y())).normalized()
            .adjusted(-20, -20, 14, 40);}
}

void Arete::updatePosition()
{
    QLineF line(mapFromItem(sommet_debut, 0, 0), mapFromItem(sommet_fin, 0, 0));
    setLine(line);
}

void Arete::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 if (sommet_debut->collidesWithItem(sommet_fin))
        return;
    QPen myPen = pen();
    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);
   QLineF centerLine(sommet_debut->pos(),sommet_fin->pos());
    painter->drawLine(centerLine);

    if (isSelected()) {
        QPen pen;  // creates a default pen
        pen.setStyle(Qt::DashLine);
        pen.setWidth(3);
        pen.setBrush(Qt::blue);
        painter->setPen(pen);
        painter->drawLine(centerLine);
  }

  painter->drawText(this->boundingRect(),Qt::AlignCenter,QString::number(y));
    }
//********
int Arete:: getflot1(){
    return flot1;
}
void Arete::setflot1(int t){
    flot1=t;
}
int Arete::getflot2(){
    return flot2;
}
void Arete::setflot2(int t){
    flot2=t;
}

void Arete::setcout(int c)
{
    x=c;
}

int Arete::getcout()
{
    return x;
}

int Arete::getcapacite(){
    return  y;
}
void Arete::setcapacite(int t){
    y=t;
}

void Arete::setarete(int t)
{
    arete=t;
}

QString Arete::creerstring(Arete *item)
{
        return QObject::tr("%1/%2/%3/%4/%5/%6/%7/%8/%9")
                .arg("Arete:").arg("debut_pos").arg(item->sommet_deb()->pos().x()).arg(item->sommet_deb()->pos().y()).
              arg("fin_pos").arg(item->sommet_f()->pos().x()).arg(item->sommet_f()->pos().y()).arg(item->getcapacite()).arg(item->getcout());;
}



