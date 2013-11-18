#ifndef QMKOMDBAPI_H
#define QMKOMDBAPI_H
/*
 *#HeaderFileName: qmkomdbapi
 *#ClassName: QMKOmdbApi,QMKOmdbApiException
 *#Developer: KaWsEr
 *#URL: https://github.com/mkawserm/QMKOmdbApi
 */




#include <QUrl>
#include <QDebug>
#include <QString>
#include <QUrlQuery>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>




class QMKOmdbApi
{

private:
    QString version;/*QMKOmdbApi Version */
    QString omdbapi_version;/*OmdbApi Version*/
    QString ua;/*User Agent*/


    QString api_url;
    QUrl request_url;
    /*OmdbApi defined variable*/
    QString s;/*Search String (optional)*/
    QString i;/*IMDb id (optional)*/
    QString t;/*IMDb movie title (optional)*/
    /*both "i" and "t" are optional at least one argument is required*/


    QString y;/*Year of the Movie (optional)*/
    QString r;/*Response type JSON or XML (JSON default)*/
    QString plot;/*short or full plot (short default)*/
    QString callback;/*name (optional) JSONP callback name*/
    QString tomatoes;/*true (optional) adds rotten tomatoes data*/


    /*Private Methods*/
    void set_default(void);
    QUrl validate_input(void);
    QString download_movie_info(QUrl &url);



public:
    QMKOmdbApi();

    void set_s(const QString &as);
    void set_search(const QString &as);

    void set_i(const QString &ai);
    void set_imdbid(const QString &ai);

    void set_t(const QString &at);
    void set_title(const QString &at);

    void set_y(const QString &ay);
    void set_year(const QString &ay);

    void set_r(const QString &ar);
    void set_response(const QString &ar);

    void set_plot(const QString &aplot);
    void set_callback(const QString &acallback);
    void set_tomatoes(const QString &atomatoes);

    QString get_s(void);
    QString get_search(void);

    QString get_i(void);
    QString get_imdbid(void);

    QString get_t(void);
    QString get_title(void);

    QString get_y(void);
    QString get_year(void);

    QString get_r(void);
    QString get_response(void);


    QString get_plot(void);
    QString get_callback(void);
    QString get_tomatoes(void);
    QString get_api_url(void);

    QString get_version(void);
    QString get_omdbapi_version(void);

    QString get_movie_info(void);
    QUrl get_request_url(void);






};


class QMKOmdbApiException
{
private:
    int ecode;
    QString error;

public:
    QMKOmdbApiException(int aecode,const QString aerror);
    QMKOmdbApiException(const QString aerror,int aecode);
    int get_ecode(void);
    QString get_error(void);


};


#endif // QMKOMDBAPI_H
