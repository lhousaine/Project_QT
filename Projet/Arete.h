#ifndef ARETE_H
#define ARETE_H

#include "sommet.h"
#include <QPen>
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
extern int ar;
extern int ac2;

class Arete : public QGraphicsLineItem
{
public:
    enum { Type= UserType + 8 };
    Arete(sommet *source, sommet *destination,QGraphicsItem *parent = 0);
    int type() const override { return Type; }
    QRectF boundingRect() const override;
    sommet *sommet_deb() const {  return sommet_debut; }
    sommet *sommet_f() const {  return sommet_fin; }
     void updatePosition();
     QString creerstring(Arete *item);
     //********
    int getflot1();
    void setflot1(int t);
     int getflot2();
     void setflot2(int t);
     void setcout(int c);
    int getcout();
     int getcapacite();
     void setcapacite(int);
     void setarete(int);
     int getarete(){return arete;}
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
private:
    sommet *sommet_debut;
    sommet *sommet_fin;
    QColor myColor;
    int y=0;//capacite
    int x=0;//cout
   int flot1=0;
   int flot2=0;
   int arete=ar;



};

#endif // ARRETE_H
