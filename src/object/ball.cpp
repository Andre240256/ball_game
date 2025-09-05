#include "include/ball.hpp"
#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>
#include <random>



#ifndef PI
#define PI 3.14159265358979323846
#endif

#define cof 0.8 //coeficcient of restitution
//constructor
Circle::Circle(double radius, Eigen::Vector2d pos,Eigen::Vector2d vel, Eigen::Vector2d acc,int res)
: radius(radius), pos(pos), vel(vel), acc(acc) , res(res), mass(radius*radius) {}


//physics properties
void Circle::updatePos()
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
void Circle::checkCollisionWithBalls(std::vector<Circle>& balls)
{
    for(int i = 0; i< balls.size(); i++)
    {
        for(int j = i + 1; j< balls.size(); j++)
        {
            if((balls[i].pos - balls[j].pos).norm() < balls[i].radius + balls[j].radius)
            {
                //collision equations
                // balls[i].vel = (balls[i].vel * (balls[i].mass - cof * balls[j].mass) + (1 + cof)*balls[j].vel * balls[j].mass)/
                // (balls[i].mass + balls[j].mass);
                // balls[j].vel = (balls[i].vel * balls[i].mass * (1+cof) + balls[j].vel * (balls[j].mass - cof * balls[i].mass))/
                // (balls[i].mass + balls[j].mass);
                
                Eigen::Vector2d normal = (balls[j].pos - balls[i].pos).normalized();
                Eigen::Vector2d normalVelocity1 = balls[i].vel.dot(normal) * normal;
                Eigen::Vector2d normalVelocity2 = balls[j].vel.dot(normal) * normal;

                
                balls[i].vel = balls[i].vel - normalVelocity1;
                balls[j].vel = balls[j].vel - normalVelocity2;
                
                balls[i].vel += (normalVelocity1 * (balls[i].mass - cof * balls[j].mass) + normalVelocity2* balls[j].mass * (1 + cof))
                / (balls[i].mass + balls[j].mass);
                balls[j].vel += (normalVelocity1 * balls[i].mass * (1+cof) + normalVelocity2 * (balls[j].mass - cof * balls[i].mass))
                / (balls[i].mass + balls[j].mass);

                balls[i].pos = balls[j].pos - normal * (balls[i].radius + balls[j].radius) * 1.02;
            }
        }
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
void Circle::drawCircle()
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