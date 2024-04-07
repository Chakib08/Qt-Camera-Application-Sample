#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Camera)
{
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture();
    m_imageSavingPath = QCoreApplication::applicationDirPath();

    ui->setupUi(this);

    // Date and time
    ui->dateTimeEdit->setReadOnly(true);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    // Edit line
    ui->lineEdit->setText(m_imageSavingPath);

    // Video Widget
    ui->videoWidget->setStyleSheet("background-color: black;");

    connect(ui->startStreamingButton, &QPushButton::clicked, this, &Camera::onStartStreaming);
    connect(ui->stopStreamingButton, &QPushButton::clicked, this, &Camera::onStopStreaming);
    connect(ui->saveButton, &QPushButton::clicked, this, &Camera::onSavingImage);
    connect(ui->selectFolderButton, &QPushButton::clicked, this, &Camera::onSelectFolder);
}

Camera::~Camera()
{
    delete ui;
}

void Camera::onStartStreaming()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera);
    m_mediaCaptureSession->setVideoOutput(ui->videoWidget);
}

void Camera::onStopStreaming()
{
    m_camera->stop();
}

void Camera::onSavingImage()
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
    m_imageCapture->captureToFile(m_imageSavingPath);
}

void Camera::onSelectFolder()
{
    QString newPath = QFileDialog::getExistingDirectory(this, "Select Directory", ui->lineEdit->text());
    if (!newPath.isEmpty()) {
        ui->lineEdit->setText(newPath);
    }
    m_imageSavingPath = newPath;
}

