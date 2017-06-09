#include <QApplication>
#include "mainwindow.h"
#include "mainwindow2.h"
#include "dialogconnect.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTranslator>
#include <QTextCodec>
#include <QLibraryInfo>

int main(int argc, char *argv[])

{    QApplication a(argc, argv);
     QSqlDatabase dbConnect=QSqlDatabase::addDatabase("QMYSQL");
      // pour la traduction
      QTranslator qtTranslator;
      //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
      QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
      qtTranslator.load("qt_" + QLocale::system().name(),
       QLibraryInfo::location(QLibraryInfo::TranslationsPath));
     //grant all privileges on dbNewWorld.* to akhasanov identified by '';
     dbConnect.setHostName("localhost");
     dbConnect.setDatabaseName("dbNewWorld_v1");
     dbConnect.setUserName("akhasanov");
     dbConnect.setPassword("jamas003");
     if(dbConnect.open())
     {
         DialogConnect dialogConnect;
         while(dialogConnect.exec()==QDialog::Accepted)
         {
         QString login=dialogConnect.getLogin();
         QString mdp=dialogConnect.getMdp();
         QSqlQuery laRequete;
         QString texteRequete = "select * from personnel where login='"+login+"' collate utf8_bin and mdp="+mdp+" ;"; // collate utf8_bin por la sensibilité
         qDebug()<<texteRequete;
         qDebug()<<texteRequete;
         bool Requete=laRequete.exec(texteRequete);
         if(Requete==false){
             dialogConnect.setMessage();
         }
          while(laRequete.next())
          {
             QString type=laRequete.value("typePersonnel").toString();
             qDebug()<<type;
             QString idConnected = laRequete.value(0).toString();
             qDebug()<<idConnected;

             if(type=="control") {
                 MainWindow2 w2(idConnected);
                 w2.show();
                 return a.exec();
             } else {
                 if(type=="gestion") {
                 MainWindow w;
                 w.show();
                 return a.exec();}
                 }
         }

         }

     }
     else
     {
         qDebug() << "erreur de connexion à la base de donnée" << endl;
         return -125;
     }
 }
