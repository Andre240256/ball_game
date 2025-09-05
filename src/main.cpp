#include <iostream>
#include <GLFW/glfw3.h>


#include "include/ball.hpp"
#include "include/window.hpp"
#include "include/vector_balls.hpp"

#define screenWidth 800
#define screenHeight 600

//functions
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

//global variables
Circles vecBalls;
Window display (screenWidth, screenHeight, "Fis Engine");

int main()
{
    if(!display.init())
        return -1;
    

    int i = 0;

    glfwSetMouseButtonCallback(display.getWindow(), mouseButtonCallback);
    glViewport(0, 0, screenWidth, screenHeight); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 

    while(!glfwWindowShouldClose(display.getWindow()))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        

        
        glColor3f(1.0f, 1.0f, 1.0f); 
        for(auto& ball : vecBalls.balls)
        {
            ball.drawCircle();
            ball.updateVel();
            ball.updatePos(); // Assuming the correct method is updatePosition()
            ball.checkCollisionWithWalls(screenWidth, screenHeight);
            ball.checkCollisionWithBalls(vecBalls.balls);
        }
        
        if(!(i % 10))
        {
            std::cout<< "Mouse Position: " << display.getPosMouse().x() << " , " << display.getPosMouse().y() << std::endl;
            i = 1;
        }
        i++;

        
        glfwSwapBuffers(display.getWindow());
        glfwPollEvents();
    }
    
    glfwDestroyWindow(display.getWindow());
    glfwTerminate();
    return 0;
}



void mouseButtonCallback(GLFWwindow * window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        vecBalls.addBallToMouse(display.getPosMouse());
    }
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        vecBalls.destroyBall(display.getPosMouse());
    }
}