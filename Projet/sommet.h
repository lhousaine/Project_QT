#ifndef SOMMET_H
#define SOMMET_H
#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
class QGraphicsSceneMouseEvent;
class Arc;
class Arete;
extern int i;

class sommet : public QGraphicsItem
{
public:
     enum { Type = UserType + 15 };

     /* In a member function declaration or definition, override ensures that the function
      is virtual and is overriding a virtual function from a base class.
      The program is ill-formed (a compile-time error is generated) if this is not true.
      override is an identifier with a special meaning when used after member function declarators:
      it's not a reserved keyword otherwise.*/
     int type() const override { return Type;}

     //*******
    sommet();
    //*******
    int nombre();
    bool getmarquer();
    void setmarquer(bool);
    void addArc(Arc *arc);
    void addArete(Arete *art);
    QRectF boundingRect()const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void removeArc(Arc *arc);//delete arc
    void removeArcs();//delete arcs

    QList<Arc *> getarcs(){return arcs;}
    QList<Arete *> getaretes(){return aretes;}
    void removeArete(Arete *art);//delete arc
    void removeAretes();//delete arcs
     int sommetId();//lhouss
private:
    QList<Arc *> arcs;
    QList<Arete *> aretes;

    int j=i;
    bool marquer=false;
};
#endif
