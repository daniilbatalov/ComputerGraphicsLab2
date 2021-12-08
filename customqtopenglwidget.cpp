#include <customqtopenglwidget.h>
#include <cmath>


glm::mat3x3 customqtopenglwidget::init_turn(float phi)
{
    return glm::mat3x3(cos(phi * PI / 180.0), sin(phi * PI / 180.0), 0, -1 * sin(phi * PI / 180.0), cos(phi * PI / 180.0), 0, 0, 0, 1);
}
glm::mat3x3 customqtopenglwidget::init_move(float x, float y)
{
    return glm::mat3x3(1, 0, x,
                       0, 1, y,
                       0, 0, 1);
}
void customqtopenglwidget::move_and_turn(Wheel* wh, float vel_x, float vel_y, float rot_vel)
{
    move = init_move(vel_x, vel_y);
    turn = init_turn(-wh->get_current_angle());
    aux_turn = init_turn(wh->get_current_angle());
    aux_move = init_move(-wh->get_current_x(), -wh->get_current_y());
    aux2_move = init_move(wh->get_current_x(), wh->get_current_y());
    for(int i = 0; i < 18; i++)
    {
        wh->transform_vertex(aux_move, turn, aux2_move, move, i);
    }
    aux_move = init_move(-wh->get_current_x() - vel_x, -wh->get_current_y() - vel_y);
    aux2_move = init_move(wh->get_current_x() + vel_x, wh->get_current_y() + vel_y);
    for(int i = 0; i < 18; i++)
    {
        wh->transform_vertex(aux_move, aux_turn, aux2_move, i);
    }
    turn = init_turn(rot_vel);
    move = init_move(-wh->get_current_x(), -wh->get_current_y());
    aux_move = init_move(wh->get_current_x(), wh->get_current_y());
    for(int i = 0; i < 18; i++)
    {
        wh->transform_vertex(move, turn, aux_move, i);
    }
    wh->add_ca(rot_vel);
    wh->add_cx(vel_x);
    wh->add_cy(vel_y);
}
void customqtopenglwidget::move_f(Frame* fr, float vel_x, float vel_y)
{
    move = init_move(vel_x, vel_y);
    for(int i = 0; i < 11; i++)
    {
        fr->transform_vertex(move, i);
    }
    fr->add_cx(vel_x);
    fr->add_cy(vel_y);
}
