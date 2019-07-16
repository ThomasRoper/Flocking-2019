#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <flock.h>
#include <boid.h>
#include <glm/glm.hpp>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
       explicit GLWidget(QWidget *parent = 0);
       void initializeGL();
       void paintGL();
       void resizeGL(int w,int h);
private:
        QTimer timer;
        Flock test;
       // Boid test;

};

#endif // GLWIDGET_H
