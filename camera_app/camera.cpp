#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Camera)
{
    ui->setupUi(this);

    connect(ui->displayButton, &QPushButton::clicked, this, &Camera::printMessage);
}

Camera::~Camera()
{
    delete ui;
}

void Camera::printMessage()
{
    qInfo() << "Hello world";
}
