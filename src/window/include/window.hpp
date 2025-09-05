#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>

#pragma once

    
class Window {
public:
    Window(int width, int height, const char* title, GLFWwindow* window = nullptr);
    bool init();
    void drawCircle(double radius, Eigen::Vector2d position, int res);

    GLFWwindow* getWindow() const;
private :
    GLFWwindow* window;
    int width;
    int height;
    const char* title;
};


