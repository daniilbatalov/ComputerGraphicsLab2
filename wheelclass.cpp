#include "wheelclass.h"


Wheel::Wheel()
{

}

Wheel::Wheel(float x0, float y0, float r, float cx, float cy, float ca, float rv)
{
    wheel_d.append(glm::vec3(x0, y0, 1));
    for (int angle = 0; angle <= 3600; angle += 225)
    {
        wheel_d.append(glm::vec3(x0 + r * cos(angle * PI / 1800.0), y0 + r * sin(angle * PI / 1800.0), 1));
    }
    current_x = cx;
    current_y = cy;
    current_angle = ca;
    radius = r;
    rotational_velocity = rv;
}

QVector<glm::vec3> Wheel::get_vertices()
{
    return wheel_d;
}
float Wheel::get_current_x()
{
    return current_x;
}
float Wheel::get_current_y()
{
    return current_y;
}
float Wheel::get_current_angle()
{
    return current_angle;
}
float Wheel::get_radius()
{
    return radius;
}
float Wheel::get_rv()
{
    return rotational_velocity;
}
void Wheel::set_vertex(glm::vec3 value, int number)
{
    wheel_d[number] = value;
}
glm::vec3 Wheel::get_vertex(int number)
{
    return wheel_d.at(number);
}
void Wheel::transform_vertex(glm::mat3x3 matrix1, glm::mat3x3 matrix2, glm::mat3x3 matrix3, int number)
{
    wheel_d[number] = wheel_d.at(number) * matrix1 * matrix2 * matrix3;
}
void Wheel::transform_vertex(glm::mat3x3 matrix1, glm::mat3x3 matrix2, glm::mat3x3 matrix3, glm::mat3x3 matrix4, int number)
{
    wheel_d[number] = wheel_d.at(number) * matrix1 * matrix2 * matrix3 * matrix4;
}
void Wheel::add_cx(float dx)
{
    current_x += dx;
}
void Wheel::add_cy(float dy)
{
    current_y += dy;
}
void Wheel::add_ca(float da)
{
    current_angle += da;
}
