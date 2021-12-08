#ifndef CUSTOMQTOPENGLWIDGET_H
#define CUSTOMQTOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <iostream>

#include "include/glm/mat3x3.hpp"
#include "include/glm/vec3.hpp"
#include "wheelclass.h"
#include "frameclass.h"

#define PI 3.14159265

class customqtopenglwidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    customqtopenglwidget(QWidget* parent = nullptr)
    {
        Q_UNUSED(parent);
        QTimer *aTimer = new QTimer;
        connect(aTimer, SIGNAL(timeout()), SLOT(update()));
        aTimer->start(25);
    }

protected:
    void initializeGL() override
    {
        glClearColor(1,1,1,1);
        if(this->objectName() == "mainOpenGLWidget")
        {
            wheel1 = Wheel(-0.8, 0.0, 0.2, -0.8, 0.0, 0.0, 1);
        }
        else
        {
            wheel1 = Wheel(-0.8, 0.0, 0.15, -0.8, 0.0, 0.0, 1);
            wheel2 = Wheel(-0.2, 0.0, 0.15, -0.2, 0.0, 0.0, 1);
            frame1 = Frame(-0.8, 0.0, 0.15, -0.2, 0.0, -0.8, 0.0);
        }
    }
    void paintGL() override
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glLineWidth(1.5);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glEnd();
        if(this->objectName() == "mainOpenGLWidget")
        {

            glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < 18; i++)
            {
                if (i == 6 || i == 7)
                {
                    glColor3f(0.80f, 0.20f, 0.25f);
                }
                glVertex2f(wheel1.get_vertices().at(i).x, wheel1.get_vertices().at(i).y);
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glEnd();
            move_and_turn(&wheel1, 2 * PI * wheel1.get_radius() * wheel1.get_rv() / 360, 0, wheel1.get_rv());
        }
        else
        {
            glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < 18; i++)
            {
                if (i == 6 || i == 7)
                {
                    glColor3f(0.80f, 0.20f, 0.25f);
                }
                glVertex2f(wheel1.get_vertices().at(i).x, wheel1.get_vertices().at(i).y);
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glEnd();
            glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < 18; i++)
            {
                if (i == 6 || i == 7)
                {
                    glColor3f(0.80f, 0.20f, 0.25f);
                }
                glVertex2f(wheel2.get_vertices().at(i).x, wheel2.get_vertices().at(i).y);
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glEnd();
            glLineWidth(2.5);
            glBegin(GL_LINE_LOOP);
            glVertex2f(frame1.get_vertices().at(0).x, frame1.get_vertices().at(0).y);
            glVertex2f(frame1.get_vertices().at(1).x, frame1.get_vertices().at(1).y);
            glVertex2f(frame1.get_vertices().at(2).x, frame1.get_vertices().at(2).y);
            glEnd();
            glBegin(GL_LINES);
            for(int i = 3; i <=8; i++)
            {
                glVertex2f(frame1.get_vertices().at(i).x, frame1.get_vertices().at(i).y);
            }
            glEnd();
            glBegin(GL_LINE_LOOP);
            glVertex2f(frame1.get_vertices().at(8).x, frame1.get_vertices().at(8).y);
            glVertex2f(frame1.get_vertices().at(9).x, frame1.get_vertices().at(9).y);
            glVertex2f(frame1.get_vertices().at(10).x, frame1.get_vertices().at(10).y);
            glEnd();
            move_and_turn(&wheel1, 2 * PI * wheel1.get_radius() * wheel1.get_rv() / 360, 0, wheel1.get_rv());
            move_and_turn(&wheel2, 2 * PI * wheel2.get_radius() * wheel2.get_rv() / 360, 0, wheel2.get_rv());
            move_f(&frame1, 2 * PI * wheel1.get_radius() * wheel1.get_rv() / 360, 0);
        }
    }

private:
    Wheel wheel1;
    Wheel wheel2;
    Frame frame1;
    glm::mat3x3 turn;
    glm::mat3x3 aux_turn;
    glm::mat3x3 move;
    glm::mat3x3 aux_move;
    glm::mat3x3 aux2_move;
    glm::mat3x3 init_turn(float phi);
    glm::mat3x3 init_move(float x, float y);
    void move_and_turn(Wheel* wh, float vel_x, float vel_y, float rot_vel);
    void move_f(Frame* fr, float vel_x, float vel_y);
};

#endif // CUSTOMQTOPENGLWIDGET_H
