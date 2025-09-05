#include "include/ball.hpp"
#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>



#ifndef PI
#define PI 3.14159265358979323846
#endif

#define cof 0.8 //coeficcient of colision
//constructor
Circle::Circle(double radius, Eigen::Vector2d pos,Eigen::Vector2d vel, Eigen::Vector2d acc,int res)
: radius(radius), pos(pos), vel(vel), acc(acc) , res(res){}

//physics properties
void Circle::udpatePos()
{
    pos += vel;
}
void Circle::updateVel()    
{
    vel += acc;
}
void Circle::checkCollisionWithWalls(int width, int height)
{
    if(pos.x() - radius < 0) // Left wall
    {
        pos.x() = radius;
        vel.x() = -cof*vel.x();
    }
    else if(pos.x() + radius > width) // Right wall
    {
        pos.x() = width - radius;
        vel.x() = -cof*vel.x();
    }

    if(pos.y() - radius < 0) // Bottom wall
    {
        pos.y() = radius;
        vel.y() = -cof*vel.y();
    }
    else if(pos.y() + radius > height) // Top wall
    {
        pos.y() = height - radius;
        vel.y() = -cof*vel.y();
    }
}

//getters
double Circle::getRadius() const { return radius; }
Eigen::Vector2d Circle::getPos() const { return pos; }
Eigen::Vector2d Circle::getVel() const { return vel; }
Eigen::Vector2d Circle::getAcc() const { return acc; }
int Circle::getRes() const { return res; }

//setters
void Circle::setRadius(double radius) { this->radius = radius; }
void Circle::setPos(Eigen::Vector2d pos) { this->pos = pos; }
void Circle::setVel(Eigen::Vector2d vel) { this->vel = vel; }
void Circle::setAcc(Eigen::Vector2d acc) { this->acc = acc; }
void Circle::setRes(int res) { this->res = res; }

//destructor
Circle::~Circle() {}

//drawCircle
void Circle::drawCircle(GLFWwindow* window)
{
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(pos.x(), pos.y()); // Center of circle
    for(int i = 0; i <= res; i++) {
        double angle = i * 2.0 * PI / res;
        double x = pos.x() + radius * cos(angle);
        double y = pos.y() + radius * sin(angle);
        glVertex2d(x, y);
    }
    glEnd();
}