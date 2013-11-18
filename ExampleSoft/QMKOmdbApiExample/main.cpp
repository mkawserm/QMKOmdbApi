#include "mainwindow.h"
#include <QApplication>
#include <QDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*
    QMKOmdbApi *oa = new QMKOmdbApi();
    oa->set_t("Brave Heart");
    oa->set_plot("full");
    oa->set_tomatoes("true");
    //oa->set_r("XML");

    try{
        qDebug() << oa->get_movie_info();
    }
    catch(QMKOmdbApiException ex){
        qDebug() << ex.get_error();
    }
    */


    MainWindow w;
    w.show();
    
    return a.exec();
}
