#include "mainwindow.h"
#include "ui_mainwindow.h"






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect( this->ui->load , SIGNAL(clicked()), this , SLOT( load_click() ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::load_click(){
    //this->oa.set_t("Brave Heart");
    this->ui->output->setText("Loading Information......\n");
    if ( !this->ui->i_t->text().isEmpty() ) oa.set_t( this->ui->i_t->text() );
    if ( !this->ui->i_y->text().isEmpty() ) oa.set_y( this->ui->i_y->text() );
    if ( !this->ui->i_i->text().isEmpty() ) oa.set_i( this->ui->i_i->text() );
    if ( !this->ui->i_s->text().isEmpty() ) oa.set_s( this->ui->i_s->text() );
    if ( !this->ui->i_r->text().isEmpty() ) oa.set_r( this->ui->i_r->text() );

    if ( !this->ui->i_plot->text().isEmpty() ) oa.set_plot( this->ui->i_plot->text() );
    if ( !this->ui->i_callback->text().isEmpty() ) oa.set_callback( this->ui->i_callback->text() );
    if ( !this->ui->i_tomatoes->text().isEmpty() ) oa.set_tomatoes( this->ui->i_tomatoes->text() );








    try{
        this->ui->output->append( oa.get_movie_info() );
        //qDebug() << oa.get_movie_info();
    }
    catch(QMKOmdbApiException ex){
        this->ui->output->append( ex.get_error() );
        //qDebug() << ex.get_error();
    }

    this->ui->output->append( "\nRequest Url: "+oa.get_request_url().toString() );
    this->ui->output->append("");
    this->ui->output->append( "Loaded......" );


}
