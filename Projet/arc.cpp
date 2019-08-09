#include "Arc.h"

const double Pi = 3.14159;
const double TwoPi = 2.0 * Pi;
Arc::Arc(sommet *source, sommet *dest, QGraphicsItem *parent):QGraphicsLineItem(parent)
{
    sommet_debut = source;
    sommet_fin = dest;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = Qt::black;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

QRectF Arc::boundingRect() const
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

void Arc::setarc(int t){arc=t;}

void Arc::updatePosition()
{
    QLineF line(mapFromItem(sommet_debut, 0, 0), mapFromItem(sommet_fin, 0, 0));
    qreal length = line.length();

   prepareGeometryChange();

    if (length > qreal(40)) {
        QPointF som_out((line.dx() * 20) / length, (line.dy() * 20) / length);
        sourcePoint = line.p1();
        destPoint = line.p2() - som_out;
    } else {
        sourcePoint = destPoint = line.p1();
    }
   setLine(line);
}

void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 if (sommet_debut->collidesWithItem(sommet_fin))
        return;
    QPen myPen = pen();
    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);
     QLineF centerLine(sourcePoint, destPoint);
    painter->drawLine(centerLine);

 //notre flesh
    double angle = ::acos(centerLine.dx() / centerLine.length());

   if (centerLine.dy() >= 0) angle = TwoPi - angle;

   QPointF destArc1 = destPoint + QPointF(sin(angle - Pi / 3) * fleshSize,
                                             cos(angle - Pi / 3) * fleshSize);
   QPointF destArc2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * fleshSize,
                                             cos(angle - Pi + Pi / 3) * fleshSize);
    painter->setBrush(Qt::white);
    painter->drawPolygon(QPolygonF() << centerLine.p2() << destArc1 << destArc2);

if (isSelected()) {
          QPen pen;  // creates a default pen
          pen.setStyle(Qt::DashLine);
          pen.setWidth(3);
          pen.setBrush(Qt::blue);
          painter->setPen(pen);
          painter->setPen(QPen(Qt::blue,3));
          painter->drawLine(centerLine);
    }

painter->drawText(this->boundingRect(),Qt::AlignCenter,QString::number(y));
}
void Arc:: setflot(int a){
    flot=a;
}
int Arc::getflot(){
    return flot;
}
void Arc::setcout(int c)
{
     x=c;
}

int Arc::getcout()
{
    return x;
}

int Arc::getcapacite(){
    return y;
    }

void Arc::setcapacite(int t){
    y=t;
}

int Arc::getarc(){
    return arc;
   }

QString Arc::creerstring(Arc *item)
{
        return QObject::tr("%1/%2/%3/%4/%5/%6/%7/%8/%9")
                  .arg("Arc:").arg("debut_pos").arg(item->sommet_deb()->pos().x()).arg(item->sommet_deb()->pos().y()).
                arg("fin_pos").arg(item->sommet_f()->pos().x()).arg(item->sommet_f()->pos().y()).arg(item->getcapacite()).
                arg(item->getcout());
}
