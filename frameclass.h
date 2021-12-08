#ifndef FRAME_H
#define FRAME_H

#include <QVector>

#include "include/glm/mat3x3.hpp"
#include "include/glm/vec3.hpp"


class Frame
{
public:
    Frame();
    Frame(float x0, float y0, float r, float x1, float y1, float cx, float cy);
    QVector<glm::vec3> get_vertices();
    void transform_vertex(glm::mat3x3 matrix, int number);
    void add_cx(float dx);
    void add_cy(float dy);
private:
    QVector<glm::vec3> frame_d;
    float current_x, current_y;
};

#endif // FRAME_H
