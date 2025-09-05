#include <iostream>
#include <GLFW/glfw3.h>


#include "include/ball.hpp"
#include "include/window.hpp"


int main()
{
    Window display (800, 600, "Fis Engine");;
    if(!display.init())
        return -1;
    
    Eigen::Vector2d pos(400, 300);
    
    Circle ball (100, pos);

    ball.setAcc(Eigen::Vector2d(0.0, 1.0));

    glViewport(0, 0, 800, 600); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0, 800, 0, 600, -1, 1); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 

    while(!glfwWindowShouldClose(display.getWindow()))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glColor3f(1.0f, 1.0f, 1.0f); 
        ball.drawCircle(display.getWindow());
        
        ball.updateVel();
        ball.udpatePos();
        ball.checkCollisionWithWalls(800, 600);
        
        glfwSwapBuffers(display.getWindow());
        glfwPollEvents();
    }
    
    glfwDestroyWindow(display.getWindow());
    glfwTerminate();
    return 0;
}