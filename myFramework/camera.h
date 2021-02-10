/**
 * @file camera.h
 *
 * @brief The Camera header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef CAMERA_H
#define CAMERA_H

#include<iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
    public:
        ///@brief Constructor of the Camera
        Camera();

        ///@brief Destructor of the Camera
        virtual ~Camera();

        ///@brief Get the viewmatrix of the Camera
        ///@return glm::mat4 viewMatrix
        glm::mat4 getViewMatrix() { return viewMatrix; }

        ///@brief Get the projectionmatrix of the Camera
        ///@return glm::mat4 projectionMatrix
        glm::mat4 getProjectionMatrix() { return projectionMatrix; }

        ///@brief Moves the camera using keyboard and mouse input
        ///@param _window The application window.
        ///@param _width The width of the window.
        ///@param _height The height of the window.
        ///@param _deltaTime The time that's passed since the last update.
        ///@return void
        void computeMatricesFromInputs(GLFWwindow* _window, unsigned int _width, unsigned int _height, float _deltaTime);

    private:

        ///@brief The viewMatrix of the Camera.
        glm::mat4 viewMatrix;

        ///@brief The projectionMatrix of the Camera.
        glm::mat4 projectionMatrix;

        ///@brief The offset of the Camera.
        glm::vec3 offset;

        ///@brief The current position of the Camera.
        glm::vec3 position;

        ///@brief The initial horizontal angle of the Camera.
        float initialHorizontalAngle;

        ///@brief The current horizontal angle of the Camera.
        float horizontalAngle;

        ///@brief The current vertical angle of the Camera.
        float verticalAngle;

        ///@brief The initial field of vision (FOV) of the Camera.
        float initialFoV;

        ///@brief The speed at which the Camera moves.
        float speed;

        ///@brief The mouse sensitivity which controls how fast the Camera rotates.
        float mouseSpeed;
};

#endif
