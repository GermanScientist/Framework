#ifndef CAMERA_H
#define CAMERA_H

#include<iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

class Camera {
    public:
        Camera();
        virtual ~Camera();

        glm::mat4 getViewMatrix() { return viewMatrix; }
        glm::mat4 getProjectionMatrix() { return projectionMatrix; }

        void computeMatricesFromInputs(GLFWwindow* _window, unsigned int _width, unsigned int _height, float _deltaTime);

    private:

        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;

        glm::vec3 offset;
        glm::vec3 position;

        float initialHorizontalAngle;
        float horizontalAngle;

        float verticalAngle;

        float initialFoV;

        float speed;
        float mouseSpeed;
};

#endif
