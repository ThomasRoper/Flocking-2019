#include "glwidget.h"
#include <GL/glut.h>


#define WIDTH 350
#define HEIGHT 350

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0.3,0.3,0.3,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glScalef(0.1,0.1,0.1);
    std::cout<<"just 100 please\n";
    test.addNewBoids(100);

};
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    test.update();
    /*

    test.seekTest();

    test.stayInWalls();
    test.Update(0.0,0.0);
    test.drawBoid();
    */
    //rough
    glBegin(GL_LINES);
    glVertex3f(-2.0,-2.0,-2.0);
    glVertex3f(-2.0,2.0,-2.0);
    glVertex3f(-2.0,-2.0,-2.0);
    glVertex3f(2.0,-2.0,-2.0);
    glVertex3f(-2.0,-2.0,-2.0);
    glVertex3f(-2.0,-2.0,2.0);

    glVertex3f(-2.0,2.0,-2.0);
    glVertex3f(-2.0,2.0,2.0);
    glVertex3f(-2.0,2.0,-2.0);
    glVertex3f(2.0,2.0,-2.0);

    glVertex3f(-2.0,2.0,2.0);
    glVertex3f(2.0,2.0,2.0);
    glVertex3f(-2.0,2.0,2.0);
    glVertex3f(-2.0,-2.0,2.0);
    glVertex3f(-2.0,-2.0,2.0);
    glVertex3f(2.0,-2.0,2.0);

    glVertex3f(2.0,2.0,2.0);
    glVertex3f(2.0,2.0,-2.0);
    glVertex3f(2.0,2.0,2.0);
    glVertex3f(2.0,-2.0,2.0);

    glVertex3f(2.0,-2.0,-2.0);
    glVertex3f(2.0,2.0,-2.0);
    glVertex3f(2.0,-2.0,-2.0);
    glVertex3f(2.0,-2.0,2.0);


    glEnd();
    glRotatef(0.2,0,1,0);

}
void GLWidget::resizeGL(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,  0,0,0,  0,1,0);
}
