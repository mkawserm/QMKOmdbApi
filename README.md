QMKOmdbApi
==========

QMKOmdbApi is the Qt5 implementation of Open Movie Database Api (http://www.omdbapi.com/)



Example Usage 1:

    QMKOmdbApi *oa = new QMKOmdbApi();
    oa->set_t("Brave Heart");   // Set title of the movie
    oa->set_plot("full");       //set plot type full or short
    oa->set_tomatoes("true");   //set tomatoes info
    oa->set_r("JSON");          //set return type

    try{
        qDebug() << oa->get_movie_info();   //Get Movie Information in JSON formatted QString
    }
    catch(QMKOmdbApiException ex){
        qDebug() << ex.get_error();
    }
    

Example Usage 2:

    QMKOmdbApi *oa = new QMKOmdbApi();
    oa->set_s("Brave Heart");   // Set search string of the movie
    oa->set_r("XML");          //set return type

    try{
        qDebug() << oa->get_movie_info();   //Get Movie Information in XML formatted QString
    }
    catch(QMKOmdbApiException ex){
        qDebug() << ex.get_error();
    }
    


Example Usage 3:

    QMKOmdbApi *oa = new QMKOmdbApi();
    oa->set_i("tt0113277");   // Set IMDbid of the movie
    oa->set_plot("full");       //set plot type full or short
    oa->set_tomatoes("true");   //set tomatoes info
    oa->set_r("JSON");          //set return type

    try{
        qDebug() << oa->get_movie_info();   //Get Movie Information in JSON formatted QString
    }
    catch(QMKOmdbApiException ex){
        qDebug() << ex.get_error();
    }
    



