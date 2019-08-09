#ifndef ARC_H
#define ARC_H
#include "sommet.h"
class QGraphicsLineItem;
class QGraphicsPolygonItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
extern int ar;
extern int ac2;
class Arc : public QGraphicsLineItem
{

public:
    enum { Type = UserType + 4 };
    Arc(sommet *source, sommet *destination,QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    sommet *sommet_deb() const {  return sommet_debut; }
    sommet *sommet_f() const {  return sommet_fin; }
    void updatePosition();
    QString creerstring(Arc *item);
    QRectF boundingRect() const override;
 //***********
    int getflot();
    void setflot(int t);
    void setcout(int c);
    int getcout();
    int getcapacite();
    void setcapacite(int t);
    int getarc();
    void setarc(int);
    //*********
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
private:
    sommet *sommet_debut;
    sommet *sommet_fin;
    QColor myColor;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal fleshSize=10;
    int y=0;//capacite
    int x=0;//cout
    int flot=0;
    int arc=ac2;

};
//

#endif // ARRETE_H
