#include <iostream>
#include <Eigen/Dense>
#include <GLFW/glfw3.h>
#include <vector>

#pragma once



class Circle{
public:
    Circle(double radius, Eigen::Vector2d pos, Eigen::Vector2d vel = Eigen::Vector2d(0.0 , 0.0) , Eigen::Vector2d acc = Eigen::Vector2d(0.0 , 0.0), int res = 100);
    void drawCircle(GLFWwindow* window);

    //physics properties
    void udpatePos();
    void updateVel();
    void checkCollisionWithWalls(int width, int height);


    //getters
    double getRadius() const;
    Eigen::Vector2d getPos() const;
    Eigen::Vector2d getVel() const;
    Eigen::Vector2d getAcc() const;
    int getRes() const;
    
    //setters
    void setRadius(double radius);
    void setPos(Eigen::Vector2d pos);
    void setVel(Eigen::Vector2d vel);
    void setAcc(Eigen::Vector2d acc);
    void setRes(int res);

    
    ~Circle();
private:
    double radius;
    Eigen::Vector2d pos;
    Eigen::Vector2d vel;
    Eigen::Vector2d acc;
    int res;
};
