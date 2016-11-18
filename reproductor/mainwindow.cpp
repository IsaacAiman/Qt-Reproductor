#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create central widget and set main layout
    wgtMain_ = new QWidget(this);
    lytMain_ = new QGridLayout(wgtMain_);
    wgtMain_->setLayout(lytMain_);
    setCentralWidget(wgtMain_);



    //Initialize widgets
    mediaPlayer_  = new QMediaPlayer(this);
    playerSlider_ = new QSlider(Qt::Horizontal, this);
    videoWidget_  = new QVideoWidget(this);
    volumeSlider_ = new QSlider(Qt::Horizontal, this);
    btnOpen_      = new QToolButton(this);
    btnPlay_      = new QToolButton(this);
    btnPause_     = new QToolButton(this);
    btnStop_      = new QToolButton(this);
    menu_         = new QMenuBar(wgtMain_);


    //Setup widwgets
    videoWidget_->setMinimumSize(400, 400);
    mediaPlayer_->setVideoOutput(videoWidget_);
    mediaPlayer_->setVolume(100);
    videoWidget_->setAspectRatioMode(Qt::KeepAspectRatio);
    volumeSlider_->setRange(0, 100);
    volumeSlider_->setSliderPosition(100);


    //Create menus
    createMenus();
    createActions();



    //Populate grid layout
    lytMain_->addWidget(menu_, 0,0,1,5);
    lytMain_->addWidget(videoWidget_,  1, 0, 1, 5);
    lytMain_->addWidget(playerSlider_, 2, 0, 1, 5);
    lytMain_->addWidget(btnOpen_,      3, 0, 1, 1);
    lytMain_->addWidget(btnPlay_,      3, 1, 1, 1);
    lytMain_->addWidget(btnPause_,     3, 2, 1, 1);
    lytMain_->addWidget(btnStop_,      3, 3, 1, 1);
    lytMain_->addWidget(volumeSlider_, 3, 4, 1, 1);
    //lytMain_->addWidget(videoWidget_,  2, 2, 1, 5);

    //Buttons icons
    btnOpen_->setIcon(QIcon(QPixmap(":/icons/resources/eject.png")));
    btnPause_->setIcon(QIcon(QPixmap(":/icons/resources/pause.png")));
    btnPlay_->setIcon(QIcon(QPixmap(":/icons/resources/play.png")));
    btnStop_->setIcon(QIcon(QPixmap(":/icons/resources/stop.png")));

    //Connections
    connect(btnOpen_,           SIGNAL(pressed()),               this,         SLOT(onOpen()));
    connect(btnPlay_,           SIGNAL(pressed()),               mediaPlayer_, SLOT(play()));
    connect(btnPause_,          SIGNAL(pressed()),               mediaPlayer_, SLOT(pause()));
    connect(btnStop_,           SIGNAL(pressed()),               mediaPlayer_, SLOT(stop()));
    connect(playerSlider_,      SIGNAL(sliderReleased()),        this,         SLOT(onSeek()));
    connect(mediaPlayer_,       SIGNAL(durationChanged(qint64)), this,         SLOT(onDurationChanged(qint64)));
    connect(mediaPlayer_,       SIGNAL(positionChanged(qint64)), this,         SLOT(onPositionChanged(qint64)));
    connect(volumeSlider_,      SIGNAL(sliderMoved(int)),        this,         SLOT(onVolumeChanged(int)));
    connect(action_archivo_,    SIGNAL(triggered()),             this,         SLOT(onOpen()));
    connect(action_ayuda_,      SIGNAL(triggered()),             this,         SLOT(acercaDe()));
    connect(action_fullscreen_, SIGNAL(triggered()),             this,         SLOT(pantallaCompleta()));
    connect(action_metadatos_,  SIGNAL(triggered()),             this,         SLOT(metadatos()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::onOpen()
{
    //Show file open dialog
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Abrir archivo"));
    if (fileName != "") {
        mediaPlayer_->setMedia(QUrl::fromLocalFile(fileName));
    }
}

void MainWindow::onSeek()
{
    mediaPlayer_->setPosition(playerSlider_->sliderPosition());
}

void MainWindow::onDurationChanged(qint64 duration)
{
    playerSlider_->setRange(0, duration);
}

void MainWindow::onPositionChanged(qint64 position)
{
    playerSlider_->setSliderPosition(position);
}

void MainWindow::onVolumeChanged(int volume)
{
    mediaPlayer_->setVolume(volume);
}

void MainWindow::pantallaCompleta()
{

    if(videoWidget_->isFullScreen()){
        videoWidget_->setFullScreen(false);
    }
    else{
        videoWidget_->setFullScreen(true);
    }
}

void MainWindow::createMenus()
{
    archivo_ = new QMenu("Archivo");
    ayuda_ = new QMenu("Ayuda");
    ver_ = new QMenu("Ver");

}

void MainWindow::acercaDe()
{

    QMessageBox msgBox;
    msgBox.setText("Reproductor en Qt                                           ");
    msgBox.setInformativeText("Curso de desarrollo de aplicaciones gráficas en Qt");
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    msgBox.exec();

}



void MainWindow::createActions()
{
    //Archivo
    menu_->addMenu(archivo_);
    action_archivo_ = new QAction(tr("&Abrir"), this);
    archivo_->addAction(action_archivo_);
    //Ayuda
    menu_->addMenu(ayuda_);
    action_ayuda_ = new QAction(tr("&Acerca de"), this);
    ayuda_->addAction(action_ayuda_);
    //pantalla completa
    menu_->addMenu(ver_);
    action_fullscreen_ = new QAction(tr("&Pantalla completa"), this);
    ver_->addAction(action_fullscreen_);
    //metadatos
    action_metadatos_ = new QAction(tr("&Ver metadatos"), this);
    ver_->addAction(action_metadatos_);



}
void MainWindow::metadatos(){
    QStringList lista;
    lista = mediaPlayer_->availableMetaData();
    for (int i = 0; i<lista.size(); i++){
        qDebug()<<"for";
        qDebug()  << lista[i]<<"\n";
        qDebug() << mediaPlayer_->metaData(lista[i]);
    }
    wgtSecondary_ = new QWidget;
    wgtSecondary_->setWindowTitle("new Window");
    lytMain_->addWidget(wgtSecondary_,  0, 6, 1, 30);
}
