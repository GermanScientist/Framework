#ifndef CAMERA_H
#define CAMERA_H

#include<iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

#include <myFramework/runner.h>

void computeMatricesFromInputs(GLFWwindow* _window, unsigned int _width, unsigned int _height, float _deltaTime);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif
