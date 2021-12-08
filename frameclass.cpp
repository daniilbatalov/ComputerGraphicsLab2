#include "frameclass.h"

Frame::Frame()
{

}
Frame::Frame(float x0, float y0, float r, float x1, float y1, float cx, float cy)
{
    frame_d.append(glm::vec3(x0, y0, 1));
    frame_d.append(glm::vec3(x0 + 1.1 * r, y0 - (r / 8.0), 1));
    frame_d.append(glm::vec3(x1 - 0.35 * r, y1 + 1.61 * r, 1));
    frame_d.append(glm::vec3(x1, y1, 1));
    frame_d.append(glm::vec3(x1 - 0.65 * r, y1 + 2.99 * r, 1));
    frame_d.append(glm::vec3(x1 - 0.45 * r, y1 + 3.1 * r, 1));
    frame_d.append(glm::vec3(x1 - 0.7 * r, y1 + 2.96 * r, 1));
    frame_d.append(glm::vec3(x0 + 1.1 * r, y0 - 0.125 * r, 1));
    frame_d.append(glm::vec3(x0 + 0.7 * r, y0 + 1.72 * r, 1));
    frame_d.append(glm::vec3(x0 + 0.3 * r, y0 + 2.02 * r, 1));
    frame_d.append(glm::vec3(x0 + 1.4 * r, y0 + 2.02 * r, 1));
    current_x = cx;
    current_y = cy;
}

QVector<glm::vec3> Frame::get_vertices()
{
    return frame_d;
}
void Frame::transform_vertex(glm::mat3x3 matrix, int number)
{
    frame_d[number] = frame_d.at(number) * matrix;
}

void Frame::add_cx(float dx)
{
    current_x += dx;
}
void Frame::add_cy(float dy)
{
    current_y += dy;
}
