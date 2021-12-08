#ifndef WHEELCLASS_H
#define WHEELCLASS_H

#include <QVector>

#include "include/glm/mat3x3.hpp"
#include "include/glm/vec3.hpp"

#define PI 3.14159265

class Wheel
{
public:
    Wheel();
    Wheel(float x0, float y0, float r, float cx, float cy, float ca, float rv);
    QVector<glm::vec3> get_vertices();
    float get_current_x();
    float get_current_y();
    float get_current_angle();
    float get_radius();
    float get_rv();
    void set_vertex(glm::vec3 value, int number);
    glm::vec3 get_vertex(int number);
    void transform_vertex(glm::mat3x3 matrix1, glm::mat3x3 matrix2, glm::mat3x3 matrix3, int number);
    void transform_vertex(glm::mat3x3 matrix1, glm::mat3x3 matrix2, glm::mat3x3 matrix3, glm::mat3x3 matrix4, int number);
    void add_cx(float dx);
    void add_cy(float dy);
    void add_ca(float da);
private:
    QVector<glm::vec3> wheel_d;
    float current_x, current_y, current_angle, radius, rotational_velocity;
};

#endif // WHEELCLASS_H
