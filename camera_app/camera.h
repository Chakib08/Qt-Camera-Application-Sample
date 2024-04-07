#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QDateTime>


/* Qt Camera incules */
#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>

#include <QVideoWidget>

#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Camera; }
QT_END_NAMESPACE

class Camera : public QWidget
{
    Q_OBJECT

public:
    Camera(QWidget *parent = nullptr);
    ~Camera();

private slots:
    void onStartStreaming();
    void onStopStreaming();
    void onSavingImage();
    void onSelectFolder();

private:
    Ui::Camera *ui;

    /* Camera attributes member */
    QCamera *m_camera;
    QMediaCaptureSession *m_mediaCaptureSession;
    QImageCapture *m_imageCapture;
    QString m_imageSavingPath;
};
#endif // CAMERA_H
