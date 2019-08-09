#include "fenetre.h"

extern int i;

fenetre::fenetre(){
    menu();
    toolbar();
    graphboutton();
    algolayout();
    scene();
    centre->setLayout(hlayout);
    setCentralWidget(centre);
    setWindowTitle("Générateur de Graphe");
}

void fenetre::menu(){
       //******************la premiere bouton de notre menu "fichier"
       fichier = menuBar()->addMenu("&Fichier");//le nom de notre bouton fichier dans le menu
            nouveau = new QAction("&Nouveau fichier",this);
            nouveau->setShortcut(QKeySequence("Ctrl+N"));
            fichier ->addAction(nouveau);//bach nzido "nouveau" fichier fldakhel dyal bouton fichier
            connect(nouveau, SIGNAL(triggered()),this, SLOT(slotnewfile()));
    
            ouvrir = new QAction("&Ouvrir fichier",this);
            ouvrir->setShortcut(QKeySequence("Ctrl+O"));
            fichier ->addAction(ouvrir);
             connect(ouvrir, SIGNAL(triggered()), this, SLOT(slotopen()));

            enregistrer = new QAction("&Enregistrer",this);
            enregistrer->setShortcut(QKeySequence("Ctrl+S"));
            fichier ->addAction(enregistrer);
             connect(enregistrer, SIGNAL(triggered()),this, SLOT(slotsave()));

             enregistrer_sous = new QAction("&Enregistrer_sous",this);
             enregistrer_sous->setShortcut(QKeySequence("ALt+A"));
             fichier ->addAction(enregistrer_sous);
              connect(enregistrer_sous, SIGNAL(triggered()),this, SLOT(slotsave_as()));

            quitter = new QAction("&Quitter",this);
            quitter->setIcon(QIcon("icone1.png"));
            quitter->setShortcut(QKeySequence("Ctrl+Q"));
            fichier ->addAction(quitter);
            //******************les connect quitter enregister  ouvrire_fichier nouveau_fichier
             connect(quitter, SIGNAL(triggered()), this, SLOT(slotquit()));

           //******************la 2eme bouton de notre menu "Aide"
            aide = menuBar()->addMenu("A&ide");
            b_aide = new QAction("&besoin d'aide",this);
            b_aide->setShortcut(QKeySequence("Ctrl+H"));
            aide ->addAction(b_aide);
           connect(b_aide, SIGNAL(triggered()), this, SLOT(slotAide()));
            //******************la 3eme bouton de notre menu "a propos"
            propos = menuBar()->addMenu("A &propos");
            about =new QAction("à propos du graphe");
            about->setShortcut(QKeySequence("Ctrl+A"));
            propos->addAction(about);
            connect(about, SIGNAL(triggered()), this, SLOT(slotAbout()));
}
void fenetre::toolbar(){

     //creer la premiere button et ajouter un icone et un sous_titre de chaque icone
    QAction* newAct = new QAction(QIcon(":/new/images/nouveaufichier.png"), "&Nouveau", this);
    newAct->setShortcuts(QKeySequence::New);//This enum represent standard key bindings. They can be used to assign platform dependent keyboard shortcuts to a QAction.
    connect(newAct, SIGNAL(triggered()),this, SLOT(slotnewfile()));


    //creer la 2eme button et ajouter un icone et un sous_titre
    QAction* openAct = new QAction(QIcon(":/new/images/open.png" ), "&Ouvrir", this);
    openAct->setShortcuts(QKeySequence::Open);
      connect(openAct, SIGNAL(triggered()),this, SLOT(slotopen()));

    //creer la 3eme button et ajouter un icone et un sous_titre
    QAction* saveAct = new QAction(QIcon(":/new/images/enregistre.png" ), "&Enregistrer", this);
    saveAct->setShortcuts(QKeySequence::Save);
  connect(saveAct, SIGNAL(triggered()),this, SLOT(slotsave_as()));

    //creer la 4eme button et ajouter un icone et un sous_titre
    QAction* quitAct = new QAction(QIcon(":/new/images/delete.png" ), "&Quitter", this);
    quitAct->setShortcuts(QKeySequence::Quit);
    connect(quitAct, SIGNAL(triggered()),this, SLOT(slotquit()));

    QToolBar* fileToolBar = this->addToolBar("File" );
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    fileToolBar->addAction(quitAct);
    fileToolBar->addWidget(ggraph);
    connect(ggraph,SIGNAL(clicked()),this,SLOT(nbresometare()));

    fileToolBar->addWidget(nbrar);
    connect(nbrar,SIGNAL(clicked()),this,SLOT(slotnbrar()));
    fileToolBar->addWidget(cout1);
    connect(cout1,SIGNAL(clicked()),this,SLOT(slotcout()));
}
void fenetre::graphboutton(){
    b_sommet->setIconSize(QSize(20,20));
    b_sommet->setGeometry(70,10,100,160);
    b_sommet->setFocusPolicy(Qt::TabFocus);
    QString ImagePath1;
    ImagePath1 = ":/new/images/sommet.png";
    QPixmap imagedisplay1(ImagePath1);
    QIcon icon1(imagedisplay1);
    b_sommet->setIcon(icon1);
    vgroup->addWidget(b_sommet);
    connect(b_sommet,SIGNAL(clicked()),this,SLOT(slotSommet()));

    b_arete->setIconSize(QSize(20,20));
    b_arete->setGeometry(70,10,100,160);
    b_arete->setFocusPolicy(Qt::TabFocus);
    QString ImagePath2;
    ImagePath2 = ":/new/images/arrete.png";
    QPixmap imagedisplay2(ImagePath2);
    QIcon icon2(imagedisplay2);
    b_arete->setIcon(icon2);
    vgroup->addWidget(b_arete);
     connect(b_arete,SIGNAL(clicked()),this,SLOT(slotArrete()));
    b_arc->setIconSize(QSize(20,20));
    b_arc->setGeometry(70,10,100,160);
    b_arc->setFocusPolicy(Qt::TabFocus);
    QString ImagePath3;
    ImagePath3 = ":/new/images/arc.png";
    QPixmap imagedisplay3(ImagePath3);
    QIcon icon3(imagedisplay3);
    b_arc->setIcon(icon3);
    vgroup->addWidget(b_arc);
     connect(b_arc,SIGNAL(clicked()),this,SLOT(slotArc()));

    b_supprimer->setIconSize(QSize(20,20));
    b_supprimer->setGeometry(70,10,100,160);
    b_supprimer->setFocusPolicy(Qt::TabFocus);
    QString ImagePath;
    ImagePath = ":/new/images/supp.png";
    QPixmap imagedisplay(ImagePath);
    QIcon icon(imagedisplay);
    b_supprimer->setIcon(icon);
    vgroup->addWidget(b_supprimer);
    connect(b_supprimer,SIGNAL(clicked()),this,SLOT(deleteItem()));
    b_select->setIconSize(QSize(20,20));
    b_select->setGeometry(70,10,100,160);
    b_select->setFocusPolicy(Qt::TabFocus);
    QString ImagePath4;
    ImagePath4 = ":/new/images/select.png";
    QPixmap imagedisplay4(ImagePath4);
    QIcon icon4(imagedisplay4);
    b_select->setIcon(icon4);
    vgroup->addWidget(b_select);
    connect(b_select,SIGNAL(clicked()),this,SLOT(ItemSelected()));
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
     sceneScaleCombo->setCurrentIndex(2);
    vgroup->addWidget(sceneScaleCombo);
    connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),this, SLOT(sceneScaleChanged(QString)));
    vgroup->addStretch(0);
    groupbox->setMaximumHeight(180);
    groupbox->setMaximumWidth(120);
    groupbox->setLayout(vgroup);
    vlayout->addWidget(groupbox);
    //******
    source->setPrefix("source");
    source->setMaximum(1000);
    puits->setPrefix("puits");
    puits->setMaximum(1000);
    vlayout->addWidget(source);
    vlayout->addWidget(puits);

}

void fenetre::algolayout(){
    flotbox->addItem("flot max");
    flotbox->addItem("FMCM");
    vgroup2->addWidget(flotbox);
    vgroup2->addWidget(b_go);
    vgroup2->addStretch(0);
    groupbox2->setLayout(vgroup2);
    vlayout->addWidget(groupbox2);
    connect(flotbox, SIGNAL(currentIndexChanged(QString)),this, SLOT(recupererindicealgo()));
    //*******tarik**************************************************************************
    connect(b_go, SIGNAL(clicked()),this, SLOT(appliqueralgo()));
//**************************************************************************************
}
void fenetre::scene(){
    sene->setBackgroundBrush(Qt::white);
    sene->setSceneRect(QRect(-20,-20,800,450));
    view->setScene(sene);
    vgroup3->addWidget(view);
    groupbox3->setLayout(vgroup3);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(groupbox3);
}
//**********les slots*********//
void fenetre::slotSommet(){
    sene->x=true;
    sene->y=false;
    sene->z=false;
    sene->s=false;
    y2=false;
    z2=false;

}

void fenetre :: slotArrete(){
        sene->y=true;
        sene->z=false;
        sene->x=false;
        sene->s=false;
        y2=false;
        z2=false;
}

void fenetre::slotArc()
{
    y2=false;
    z2=false;
    sene->y=false;
    sene->z=true;
    sene->s=false;
    sene->x=false;
}

void fenetre::deleteItem()
{
    y2=false;
    z2=false;
    sene->y=false;
    sene->z=false;
    sene->x=false;
  if(sene->s==true){
    foreach (QGraphicsItem *a, sene->selectedItems()) {
        if (a->type() == Arc::Type) {
            Arc *arc = qgraphicsitem_cast<Arc *>(a);
            arc->sommet_deb()->removeArc(arc);
            arc->sommet_f()->removeArc(arc);
           sene->removeItem(a);
           //********
           int v;
           for(int i=0;i<Arcss.length();i++){

               if(Arcss[i]->getarc()==qgraphicsitem_cast<Arc *>(a)->getarc()){v=i;}
           }
           if(v<Arcss.length()){Arcss.removeAt(v);}
           //********
            delete a;
        }
    }
    foreach (QGraphicsItem *a, sene->selectedItems()) {
        if (a->type() == Arete::Type) {
            Arete *art = qgraphicsitem_cast<Arete *>(a);
            art->sommet_deb()->removeArete(art);
            art->sommet_f()->removeArete(art);
           sene->removeItem(a);
           //**************
           int v;
           for(int i=0;i<Aretess.length();i++){
               if(Aretess[i]->getarete()==qgraphicsitem_cast<Arete *>(a)->getarete()){v=i;}
           }
           if(v<Aretess.length()){Aretess.removeAt(v);}
           //**************
            delete a;

        }
    }
    foreach (QGraphicsItem *a, sene->selectedItems()) {
         if (a->type() == sommet::Type){
             qgraphicsitem_cast<sommet *>(a)->removeArcs();
             qgraphicsitem_cast<sommet *>(a)->removeAretes();
         sene->removeItem(a);
         //********
         int v;
         for(int i=0;i<sommetss.length();i++){
             if(sommetss[i]->nombre()==qgraphicsitem_cast<sommet *>(a)->nombre()){v=i;}
         }
         if(v<sommetss.length()){sommetss.removeAt(v);}
         //*******
         for(int i=0;i<qgraphicsitem_cast<sommet *>(a)->getaretes().length();i++){
             for(int j=0;j<Aretess.length();j++){
                 if(  (qgraphicsitem_cast<sommet *>(a)->getaretes())[i]->getarete()==Aretess[j]->getarete()){
                     Aretess.removeAt(j);

                 }
             }
           }
         delete a;
         }
    }
  }
  }
void fenetre::ItemSelected()
    {
        sene->x=false;
        sene->y=false;
        sene->z=false;
        sene->s=true;
        y2=true;
        z2=true;
}
void fenetre::sceneScaleChanged(const QString &scale)
{
        double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
        QMatrix oldMatrix = view->matrix();
        view->resetMatrix();
        view->translate(oldMatrix.dx(), oldMatrix.dy());
        view->scale(newScale, newScale);
}
void fenetre::slotnewfile(){
    initialisertableaux(1);
    this->raffraichirlestableaux();
    file_path="  ";
QMessageBox::StandardButton reply= QMessageBox::question
            (this,"Générateur de graphe","Est-ce-que tu veut enregitrer les modification ?",
             QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes){
    slotsave();
    sene->clear();
    }
    if(reply==QMessageBox::No){
    sene->clear();
}
    i=0;
    ac2=0;
    ar=0;
}

void fenetre::slotquit(){
    QMessageBox::StandardButton reply= QMessageBox::question
                (this,"Générateur de graphe","Est-ce-que tu veut enregitrer les modification ?",
                 QMessageBox::Yes |QMessageBox::No|QMessageBox::Close);
        if(reply==QMessageBox::Yes){
        slotsave();
            QApplication::quit();
        }
        if(reply==QMessageBox::Close){
            return;
        }
        if(reply==QMessageBox::No){
         QApplication::quit();
        }
}
void fenetre::slotAbout()
{
 QMessageBox::about(this,"À propos","Générateur de graphe qui gére les problèmes"
                                       " de flot\n\nProjet réalisé par le groupe 4\ndeveloppé avec Qt/C++");

}

void fenetre::slotAide()
{
 QMessageBox::about(this,"Aide","Générateur de graphe qui gére les problèmes de "
                                "flot\n\nProjet réalisé par le groupe 4\ndeveloppé avec Qt/C++");
}
//************************************************
void fenetre::slotsave(){
    this->raffraichirlestableaux();
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"File","the file does not saved");
        return;
    }
    QTextStream out(&file);
    QString text;
        foreach (Arc *b, Arcss) {
            text+=b->creerstring(b);
            text+="\n";
        }
        foreach (Arete *c, Aretess) {
            text+=c->creerstring(c);
            text+="\n";
       }
        /*text+="voila notre matrice d'adjacence:\n";
        for(int i=0;i<sommetss.length();i++){
            for(int j=0;j<sommetss.length();j++){
               text+=TG[i][j]+"  ";
            } text+="\n";
        }*/
     out <<text;
    file.flush();
    file.close();
}
//******************************
void fenetre::slotsave_as()
{
    initialisertableaux(1);
    this->raffraichirlestableaux();
    QString file_name=QFileDialog::getSaveFileName(this,"save this file","Text File(*.txt)");
   file_path=file_name;
   QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"File","the file does not saved");
        return;
    }
    QTextStream out(&file);
    QString text;
        foreach (Arc *b, Arcss) {
            text+=b->creerstring(b);
            text+="\n";
        }
        foreach (Arete *c, Aretess) {
            text+=c->creerstring(c);
            text+="\n";
       }
    /*    text+="voila notre matrice d'adjacence:\n";
        for(int i=0;i<sommetss.length();i++){
            for(int j=0;j<sommetss.length();j++){
               text+=TG[sommetss[i]->nombre()][sommetss[j]->nombre()]+"  ";
            }
            text+="\n";
        }*/
     out<<text;
     file.flush();
     file.close();
}
//************
void fenetre::slotopen()
{
    this->slotnewfile();
    QString file_name=QFileDialog::getOpenFileName(this,"open this file");//," Text File(*.txt)");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"File","the file you wanted does not existe");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
    QString line=in.readLine();
    QStringList elem = line.split("/");
    if(elem.at(0)=="Arc:"||elem.at(0)=="Arete:"){
    sommet*deb=new sommet();
    sommet*fin=new sommet();
    sommetss.push_back(deb);
    sommetss.push_back(fin);
    deb->setPos(QPointF(elem.at(2).toInt(),elem.at(3).toInt()));
    fin->setPos(QPointF(elem.at(5).toInt(),elem.at(6).toInt()));
    sene->addItem(deb);
    sene->addItem(fin);
    i++;
    if(elem.at(0)=="Arc:"){
        Arc*ac=new Arc(deb,fin);
        Arcss.push_back(ac);
        deb->addArc(ac);
        fin->addArc(ac);
        ac->setZValue(-10.0);
        ac->setcapacite(elem.at(7).toInt());//lhouss
        ac->setcapacite(elem.at(8).toInt());
        sene->addItem(ac);
         ac->setPen(QPen(Qt::black,2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        ac->updatePosition();
    }
    if(elem.at(0)=="Arete:"){
        Arete*ac=new Arete(deb,fin);
        Aretess.push_back(ac);
        deb->addArete(ac);
        fin->addArete(ac);
        ac->setZValue(-10.0);
        ac->setcapacite(elem.at(7).toInt());
        ac->setcapacite(elem.at(8).toInt());
        sene->addItem(ac);
         ac->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        ac->updatePosition();
    }
    }
}
  file.close();
}


//***
//*******algo***********************************************************************************************************
int n=0;
void fenetre::raffraichirlestableaux(){
initialisertableaux(1);
if(!sommetss.isEmpty()){n=sommetss.length();}
   //pour les Aretess
if(!Aretess.isEmpty()){
int i=0;
for( i=0;i<Aretess.length();i++){
TG[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=1;
TG[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=1;
F[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=Aretess[i]->getflot1();
F[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=Aretess[i]->getflot2();
C[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=Aretess[i]->getcapacite();
//********
}
}
if(!Arcss.isEmpty()){
    int i=0;
    for( i=0;i<Arcss.length();i++){
TG[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=1;
F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=Arcss[i]->getflot();
C[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=Arcss[i]->getcapacite();
  }
}
//******
for(int i=0;i<Aretess.length();i++){
//remplir Cr et TGr
if(F[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]>0){
Crm[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=F[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()];
TGrm[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=1;}

if(F[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]<C[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]){
    Crp[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=C[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]-F[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()];

    TGrp[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=1;

   }
//les cout et les cout*
// on reprend les lignes de 35 a 41 en changeant sommet_deb() et ->sommet_f()

if(F[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]>0){
Crm[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=F[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()];
TGrm[Aretess[i]->sommet_deb()->nombre()][Aretess[i]->sommet_f()->nombre()]=1;}

if(F[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]<C[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]){
    Crp[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=C[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]-F[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()];
    TGrp[Aretess[i]->sommet_f()->nombre()][Aretess[i]->sommet_deb()->nombre()]=1;
}
}

if(!Arcss.isEmpty()){
    int i=0;
    for( i=0;i<Arcss.length();i++){
//remplir Cr et TGr
if(F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]>0){
Crm[Arcss[i]->sommet_f()->nombre()][Arcss[i]->sommet_deb()->nombre()]=F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()];
TGrm[Arcss[i]->sommet_f()->nombre()][Arcss[i]->sommet_deb()->nombre()]=1;}

if(F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]<C[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]){
    Crp[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=C[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]-F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()];
    TGrp[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=1;
 }
  cout[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=Arcss[i]->getcout();
  cout[Arcss[i]->sommet_f()->nombre()][Arcss[i]->sommet_deb()->nombre()]=-Arcss[i]->getcout();
  }
}

}
void fenetre::initialiser_Lij()
{
    for(int i=0;i<Arcss.length();i++){
    Lij[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]=(cout[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()])*(F[Arcss[i]->sommet_deb()->nombre()][Arcss[i]->sommet_f()->nombre()]);
    }
}
int d;
//*
void fenetre:: chaineameliorante(){

    File.clear();
    File.push_back(this->getsource());
   int stop=0;
    int d;
    d=1;
    int v=0;
    int drapeau=0;
    int n=this->getsource()->nombre();
   while((n!=this->getpuits()-> nombre())&&((File.length()>1)||(d==1))){
       drapeau=0;
        stop=0;
        d=0;//pour dire qu'on vient de l'interieur de la boucle
  int i=0;
        for(i=0;i<sommetss.length();i++){

            this->raffraichirlestableaux();
            if((((TGrp[n][sommetss[i]->nombre()])==1 &&(Crp[n][sommetss[i]->nombre()]>0))||(((TGrm[n][sommetss[i]->nombre()])==1) &&(Crm[n][sommetss[i]->nombre()]>0)))&& (sommetss[i]->getmarquer()==false)) {



                 drapeau=1;
                 break;

           }else if((((TGrp[n][sommetss[i]->nombre()])==1 &&(Crp[n][sommetss[i]->nombre()]==0))||(((TGrm[n][sommetss[i]->nombre()])==1) &&(Crm[n][sommetss[i]->nombre()]==0))||sommetss[i]->getmarquer()==true)){
                for(int k=1;k<(File.length()-1);k++){if((this->nbrefils(File[k]))>1){stop=k;}}

                for(int k=File.length()-2;k>=stop;k--){File[k]->setmarquer(true);}

                if((File[File.length()-1]->nombre())!=(puits->value())){
                    File[File.length()-1]->setmarquer(true);
                }
                File.clear();
                File.push_back(this->getsource());
                n=this->getsource()->nombre();
                drapeau=0;
            }
            this->raffraichirlestableaux();
            }
   if(drapeau==1){  File.push_back(sommetss[i]);
           n=sommetss[i]->nombre();
}

    }
       for(int k=1;k<(File.length()-1);k++){if((this->nbrefils(File[k]))>1){stop=k;
           }
       }
       for(int k=File.length()-2;k>stop;k--){File[k]->setmarquer(true);
   }

}


//***********************************************************************
int fenetre:: flotmax(){

 int Q=0;
  int delta=1000000;
 do{
      this->chaineameliorante();
   if(File.length()>1){
     for(int i=0;i<File.length();i++){//determiner le delta
     for(int j=0;j<File.length();j++){
          if(delta>Crp[File[i]->nombre()][File[j]->nombre()]&&Crp[File[i]->nombre()][File[j]->nombre()]>0){
            delta=Crp[File[i]->nombre()][File[j]->nombre()];}
                            }
       }
     for(int i=0;i<File.length();i++){//determiner le delta
     for(int j=0;j<File.length();j++){
          if(delta>Crm[File[j]->nombre()][File[i]->nombre()]&&Crm[File[j]->nombre()][File[i]->nombre()]>0){
            delta=Crm[File[j]->nombre()][File[i]->nombre()];}
                           }
    }
     int s_1,s_2,s_3,s_4,s_5,s_6;
     for(int i=0;i<File.length();i++){//ajouter et soustraire les deltas
         for(int j=0;j<File.length();j++){
             if(TGrp[File[i]->nombre()][File[j]->nombre()]==1){//F[File[i]->nombre()][File[j]->nombre()]+=delta;

                 for(int k=0;k<Arcss.length();k++){

                     if((Arcss[k]->sommet_deb()->nombre()==File[i]->nombre())&&(Arcss[k]->sommet_f()->nombre()==File[j]->nombre())){

                         s_1=k;
                     }

                 }
                 int n_1=Arcss[s_1]->getflot();
                Arcss[s_1]->setflot(n_1+delta);

           /*  */



             }
             if(TGrm[File[i]->nombre()][File[j]->nombre()]==1){//F[File[j]->nombre()][File[i]->nombre()]-=delta;
                 int k;
                 for( k=0;k<Arcss.length();k++){

                     if((Arcss[k]->sommet_deb()->nombre()==File[j]->nombre())&&(Arcss[k]->sommet_f()->nombre()==File[i]->nombre())){
                         s_4=k;
                     }

                 }
                 int n_4=Arcss[s_4]->getflot();
                Arcss[s_4]->setflot(n_4-delta);

                /* for(int l=0;l<Aretess.length();l++){

                     if((Aretess[l]->sommet_deb()->nombre()==File[i]->nombre())&&(Aretess[l]->sommet_f()->nombre()==File[j]->nombre())){

                         s_5=l;
                     }
                     int n_5=Aretess[s_5]->getflot1();
                    Aretess[s_5]->setflot1(n_5-delta);
                 }
                 int n=Aretess[s_5]->getflot1();
                Aretess[s_5]->setflot1(n-delta);

                 for(int a=0;a<Aretess.length();a++){

                     if((Aretess[a]->sommet_deb()->nombre()==File[j]->nombre())&&(Aretess[a]->sommet_f()->nombre()==File[i]->nombre())){

                         s_6=a;
                     }
                     int n_6=Aretess[s_6]->getflot2();
                    Aretess[s_6]->setflot2(n_6-delta);
                 }*/

             }
         }

     }
     this->raffraichirlestableaux();
     Q=Q+delta;
       }
 }

 while(File.length()>1);
this->initialiser_Lij();
// initialisertableaux(2);
 return Q;
}

QQueue<sommet*>fcm;
int fenetre::flotmax_coutMin(sommet *s,sommet *t)
{
    int n=sommetss.length();
     y[0]=0;
     int C=y[0];
     for(int i=1;i<n;i++){
         y[i]=1000000;
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
                if(y[j]-y[i]>Lij[i][j])
                {
                    y[j]=Lij[i][j]+y[i];
                }
                }
                }
     fcm.enqueue(s);
     int i=n-1;
     while (i!=t->nombre()) {
         for(int j=0;j<n;j++){
             if((j!=i)&&(y[i]-y[j]==Lij[j][i])) {
              C+=y[j];
             fcm.enqueue(sommetss[j]);
             i=j;
             break;
             }
         }
     }
     return C;
}
sommet *fenetre::getsource()
{
    int i=0;
    int s;
    for( i=0;i<sommetss.length();i++){

        if(sommetss[i]->nombre()==source->value()){
            s=i;
        }
    }
    return sommetss[s];
}

sommet *fenetre::getpuits()
{
    int i=0;
    int s;
        for( i=0;i<sommetss.length();i++){


            if(sommetss[i]->nombre()==puits->value()){
                s=i;
            }
        }
        return sommetss[s];
}

int fenetre::nbrefils(sommet *s)
{
 int i;
 int c=0;
 this->raffraichirlestableaux();
 for(i=0;i<sommetss.length();i++){

     if(TG[s->nombre()][sommetss[i]->nombre()]==1){

         c++;
     }

 }
 return c;
}
void fenetre::recupererindicealgo(){
    indicealgo =flotbox->currentIndex();
}
void fenetre::appliqueralgo()
{
    if(indicealgo==0){
        int max=this->flotmax();
   QMessageBox::information(this, "Le flot max",
                                       QString("Le flot max est:\n")+QString::number(max));
    }
    QString text;
    if(indicealgo==1){
        this->flotmax_coutMin(this->getsource(),this->getpuits());
        for(int i=0;i<fcm.length();i++){
          text+=fcm[i]->nombre()+" ";
        }

    QMessageBox::information(this, "Le flot max",
                                   QString("Le flot max de cout minimum est définie par la chaine:\n")+text+
                             QString("Avec un flot maximum de cout minimum:")+flotmax_coutMin(this->getsource(),this->getpuits()));
    }
}
//******************************

//fin algo1************************************************************************************************************
int fenetre::nb(int n)
{
    if(n==0||n==1)
        return 0;
    else return nb(n-1)+n-1;
}
void fenetre::nbresometare()
{
    int k;
    bool ok;

    k=QInputDialog::getInt(this,"nombre de sommets","saisir le nombre de sommets",25, 0, 100, 1, &ok);
    if(k>=0 && ok){
        bool ok;
        nbresommets=k;
//*********************
        k=QInputDialog::getInt(this,"nombre d'aretes","saisir le nombre des aretes",nbresommets, 0,nb(nbresommets), 1, &ok);
        if(k>=0 && ok){
            nbrearetes=k;
            k=QInputDialog::getInt(this,"nombre d'arcs","saisir le nombre des arcs",2*nb(nbresommets)-nbrearetes, 0,2*nb(nbresommets)-nbrearetes, 1, &ok);
            if(k>=0 && ok){
               nbrearcs=k;
               i=0;
                generergraphe();
            }
        }

    }

}

void fenetre::slotnbrar(){
    int a;
     bool ok;
     if(z2){
     foreach (QGraphicsItem *ar, sene->selectedItems()) {
    if (ar->type() == Arc::Type) {
    a=QInputDialog::getInt(this,"valeur","saisir la valeur de l'arc ",0, 0, 100, 1, &ok);
    qgraphicsitem_cast<Arc *>(ar)->setcapacite(a);
    }
    }
     }
     if(y2){
         foreach (QGraphicsItem *ar, sene->selectedItems()) {
     if (ar->type() == Arete::Type) {
        a=QInputDialog::getInt(this,"valeur","saisir la valeur de l'arete ",0, 0, 100, 1, &ok);
       qgraphicsitem_cast<Arete *>(ar)->setcapacite(a);
         }
         }
     }
}

void fenetre::slotcout()
{
         int a;
         bool ok;
          if(z2){
         foreach (QGraphicsItem *ar, sene->selectedItems()) {
         if (ar->type() == Arc::Type) {
         a=QInputDialog::getInt(this,"valeur","saisir le cout de l'arc ",0, 0, 100, 1, &ok);
         qgraphicsitem_cast<Arc *>(ar)->setcout(a);
       }
       }}
           if(y2){
             foreach (QGraphicsItem *ar, sene->selectedItems()) {
         if (ar->type() == Arete::Type) {
            a=QInputDialog::getInt(this,"valeur","saisir le cout de l'arete ",0, 0, 100, 1, &ok);
           qgraphicsitem_cast<Arete *>(ar)->setcout(a);
             }
             }}
}

