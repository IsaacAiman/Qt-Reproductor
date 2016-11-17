#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QMessageBox>
#include <QSlider>
#include <QFileDialog>
#include <QToolButton>
#include <QMenuBar>
#include <iostream>
#include <QMediaMetaData>
#include <QMetaDataReaderControl>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    QGridLayout*        lytMain_;
    QWidget*            wgtMain_;
    QWidget*            wgtSecondary_;
    QMediaPlayer*       mediaPlayer_;
    QSlider*            playerSlider_;
    QVideoWidget*       videoWidget_;
    QSlider*            volumeSlider_;
    QToolButton*        btnOpen_;
    QToolButton*        btnPlay_;
    QToolButton*        btnPause_;
    QToolButton*        btnStop_;
    QMenuBar*           menu_;
    QMenu*              archivo_;
    QMenu*              ayuda_;
    QMenu*              ver_;
    QAction*            action_archivo_;
    QAction*            action_ayuda_;
    QAction*            action_fullscreen_;
    QAction*            action_metadatos_;

private slots:
    void createMenus();
    void metadatos();
    void pantallaCompleta();
    void createActions();
    void onOpen();
    void onSeek();
    void acercaDe();
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onVolumeChanged(int volume);

};

#endif // MAINWINDOW_H
