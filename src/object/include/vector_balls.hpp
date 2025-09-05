#include <iostream>
#include <Eigen/Dense>
#include <GLFW/glfw3.h>
#include <vector>

#include "ball.hpp"

#pragma once

class Circles{
public:
    Circles();

    void addBallToMouse(Eigen::Vector2d posMouse);
    void destroyBall(Eigen::Vector2d posMouse);
    void addBall(Circle& ball);

    //getters
    std::vector<Circle> getBalls() const;

    ~Circles();
    
    std::vector<Circle> balls;
};