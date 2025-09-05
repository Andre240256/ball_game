#include <iostream>
#include <GLFW/glfw3.h>


#include "include/window.hpp"

//constructor
Window::Window(int widht, int height, const char* title, GLFWwindow* window) 
: width(widht), height(height), title(title), window(nullptr) {}

//getters
GLFWwindow* Window::getWindow() const 
{
    return window; 
}


bool Window::init()
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    this->window = window;
    if(!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    return true;
}
