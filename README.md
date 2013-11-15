QMKOmdbApi
==========

QMKOmdbApi is the Qt5 implementation of Open Movie Database Api (http://www.omdbapi.com/)



Example Usage 1:

    QMKOmdbApi *oa = new QMKOmdbApi();
    oa->set_t("Brave Heart");
    oa->set_plot("full");
    oa->set_tomatoes("true");
    oa->set_r("JSON");

    try{
        qDebug() << oa->get_movie_info();
    }
    catch(QMKOmdbApiException ex){
        qDebug() << ex.get_error();
    }
    

