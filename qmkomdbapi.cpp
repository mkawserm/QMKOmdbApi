#include "qmkomdbapi.h"


/************QMKOmdbApiException************/

QMKOmdbApiException::QMKOmdbApiException(int aecode, const QString aerror){
    this->ecode = aecode;
    this->error = aerror;

}

QMKOmdbApiException::QMKOmdbApiException(const QString aerror, int aecode){
    this->error = aerror;
    this->ecode = aecode;
}

int QMKOmdbApiException::get_ecode(void){
    return this->ecode;
}

QString QMKOmdbApiException::get_error(void){
    return this->error;
}
/************End QMKOmdbApiException************/







/************QMKOmdbApi************/

QMKOmdbApi::QMKOmdbApi()
{
    this->set_default();
}

void QMKOmdbApi::set_default(){
    this->version = "1.0.0";/*QMKOmdbApi Version*/
    this->omdbapi_version = "2.1";
    this->api_url = "http://www.omdbapi.com";
    this->ua = "QMKOmdbApi/"+this->version+"(+https://github.com/mkawserm/QMKOmdbApi)";

}




/*Set Methods*/
void QMKOmdbApi::set_s(const QString &as){this->s = as;}
void QMKOmdbApi::set_search(const QString &as){this->set_s(as);}

void QMKOmdbApi::set_i(const QString &ai){this->i = ai;}
void QMKOmdbApi::set_imdbid(const QString &ai){this->set_i(ai);}

void QMKOmdbApi::set_t(const QString &at){this->t = at;}
void QMKOmdbApi::set_title(const QString &at){this->set_t(at);}

void QMKOmdbApi::set_y(const QString &ay){this->y = ay;}
void QMKOmdbApi::set_year(const QString &ay){this->set_y(ay);}

void QMKOmdbApi::set_r(const QString &ar){this->r = ar;}
void QMKOmdbApi::set_response(const QString &ar){this->set_r(ar);}

void QMKOmdbApi::set_plot(const QString &aplot){this->plot = aplot;}

void QMKOmdbApi::set_callback(const QString &acallback){this->callback = acallback;}

void QMKOmdbApi::set_tomatoes(const QString &atomatoes){this->tomatoes = atomatoes;}
/*End of Set Methods*/





/*Get Methods*/
QString QMKOmdbApi::get_s(void){return this->s;}
QString QMKOmdbApi::get_search(void){return this->s;}


QString QMKOmdbApi::get_i(void){return this->i;}
QString QMKOmdbApi::get_imdbid(void){return this->i;}


QString QMKOmdbApi::get_t(void){return this->t;}
QString QMKOmdbApi::get_title(void){return this->t;}


QString QMKOmdbApi::get_y(void){return this->y;}
QString QMKOmdbApi::get_year(void){return this->y;}


QString QMKOmdbApi::get_r(void){return this->r;}
QString QMKOmdbApi::get_response(void){return this->r;}


QString QMKOmdbApi::get_plot(void){return this->plot;}

QString QMKOmdbApi::get_callback(void){return this->callback;}

QString QMKOmdbApi::get_tomatoes(void){return this->tomatoes;}

QString QMKOmdbApi::get_api_url(void){return this->api_url;}

QString QMKOmdbApi::get_version(void){return this->version;}

QString QMKOmdbApi::get_omdbapi_version(void){return this->omdbapi_version;}
/*End of Set Methods*/





/*Movie Info Downloader*/
QString QMKOmdbApi::download_movie_info(QUrl &url){
    QNetworkAccessManager *qnam = new QNetworkAccessManager();
    QByteArray ua(this->ua.toUtf8());


    QNetworkRequest qnr;
    qnr.setUrl(url);
    qnr.setRawHeader("User-Agent",ua);

    QNetworkReply *reply= qnam->get(qnr);

    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()),&loop, SLOT(quit()));
    loop.exec();

    QString result = reply->readAll();


    /*Cleaning Memory*/
    delete reply;
    delete qnam;

    return result;
}




/*Validate User Input and Return A request Url*/
QUrl QMKOmdbApi::validate_input(void){
    QUrl request_url;
    QUrlQuery request_arg;

    request_url.setUrl(this->api_url);


    if ( !this->i.isEmpty() ) {
        request_arg.addQueryItem("i",this->i);
    }
    else
    {
        if ( !this->t.isEmpty() && !this->y.isEmpty() ){
            request_arg.addQueryItem("t",this->t);
            request_arg.addQueryItem("y",this->y);
        }
        else if ( !this->t.isEmpty()){
            request_arg.addQueryItem("t",this->t);

        }
        else if ( !this->s.isEmpty()){
            request_arg.addQueryItem("s",this->s);
        }

    }

    if ( this->t.isEmpty() && this->i.isEmpty() && this->s.isEmpty() ){
        throw( QMKOmdbApiException(1,"at least one must be set from i,s,t") );
    }

    if ( !this->r.isEmpty()) request_arg.addQueryItem("r",this->r);
    if ( !this->plot.isEmpty()) request_arg.addQueryItem("plot",this->plot);
    if ( !this->callback.isEmpty()) request_arg.addQueryItem("callback",this->callback);
    if ( !this->tomatoes.isEmpty()) request_arg.addQueryItem("tomatoes",this->tomatoes);




    request_url.setQuery(request_arg);
    return request_url;
}



/*Get Movie Information according to settings*/
QString QMKOmdbApi::get_movie_info(void){
    QString result;
    QUrl request_url=this->validate_input();
    result = this->download_movie_info(request_url);

    return result;
}


/************End QMKOmdbApi************/

