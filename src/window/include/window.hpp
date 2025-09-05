#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>

#pragma once

    
class Window {
public:
    Window(int width, int height, const char* title);
    bool init();
    void drawCircle(double radius, Eigen::Vector2d position, int res);
    
    
    
    
    //getters
    int getWidth() const;
    int getHeight() const;
    Eigen::Vector2d getPosMouse() const;
    GLFWwindow* getWindow() const;
    
    
    
private :
    GLFWwindow* window;
    int width;
    int height;
    const char* title;
    Eigen::Vector2d posMouse;
    
    
    void handleCursorPos(double xpos, double ypos);
    
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
};


