#include <iostream>
#include <Eigen/Dense>
#include <GLFW/glfw3.h>
#include <vector>
#include <random>

#include "include/vector_balls.hpp"

#pragma once

//constructor
Circles::Circles() {}

//destructor
Circles::~Circles() {}


//mouse interactions
void Circles::addBallToMouse(Eigen::Vector2d posMouse)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> dis(10.0, 70.0);
    double radius = dis(gen);

    std::uniform_real_distribution<double> disVel(-2.0, 2.0);
    Eigen::Vector2d vel(disVel(gen), disVel(gen));

    std::uniform_real_distribution<double> disAcc(-0.2, 0.2);
    Eigen::Vector2d acc(disAcc(gen), -0.1);

    Circle newBall(radius, posMouse, vel, acc);
    newBall.drawCircle();
    balls.push_back(newBall);
}

void Circles::destroyBall(Eigen::Vector2d posMouse)
{
    for(auto it = balls.begin(); it != balls.end(); ++it)
    {
        if((it->getPos()- posMouse).norm() < it->getRadius())
        {
            balls.erase(it);
            break;
        }
    }
}


void Circles::addBall(Circle& ball)
{
    balls.push_back(ball);
}

//getters
std::vector<Circle> Circles::getBalls() const
{
    return balls;
}