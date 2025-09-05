#include <iostream>
#include <GLFW/glfw3.h>

#include "include/vector_balls.hpp"
#include "include/window.hpp"

#define screenWidth 800
#define screenHeight 600

//constructor
Window::Window(int widht, int height, const char* title) 
: width(widht), height(height), title(title) {}

//getters
GLFWwindow* Window::getWindow() const 
{
    return window; 
}
int Window::getWidth() const
{
    return width;
}
int Window::getHeight() const
{
    return height;
}
Eigen::Vector2d Window::getPosMouse() const
{
    return posMouse;
}


bool Window::init()
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    this->window= glfwCreateWindow(width, height, title, nullptr, nullptr);
    if(!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwSetWindowUserPointer(this->window, this);

    glfwMakeContextCurrent(this->window);

    glfwSetCursorPosCallback(this->window, cursorPosCallback);
    return true;
}

void Window::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    Window* my_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if(my_window)
    {
        my_window->handleCursorPos(xpos, ypos);
    }
}

void Window::handleCursorPos(double xpos, double ypos)
{
    posMouse = Eigen::Vector2d(xpos, screenHeight-ypos);
}

