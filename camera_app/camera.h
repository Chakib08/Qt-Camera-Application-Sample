#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>

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
    void printMessage();

private:
    Ui::Camera *ui;
};
#endif // CAMERA_H
