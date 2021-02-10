/**
 * @file textureloader.h
 *
 * @brief The Textureloader header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <iostream>
#include <cstdio>

#include <string>
#include <GL/glew.h>

class Textureloader {
    public:
        ///@brief Constructor of the Textureloader.
        Textureloader();

        ///@brief Destructor of the Textureloader.
        virtual ~Textureloader();

        ///@brief Loads a .BMP file.
        ///@param _imagepath The file location of the image that needs to be loaded.
        ///@return GLuint textureID
        GLuint loadCustomBMP(const char* _imagepath);

        ///@brief Loads a .DDS file.
        ///@param _imagepath The file location of the image that needs to be loaded.
        ///@return GLuint textureID
        GLuint loadDDS(const char* _imagepath);

        ///@brief Loads a .TGA file.
        ///@param _imagepath The file location of the image that needs to be loaded.
        ///@return GLuint textureID
        GLuint loadTGA(const std::string& _imagepath);

        ///@brief Gets the width of the texture.
        ///@return unsigned int width
        unsigned int getWidth() { return width; };

        ///@brief Gets the height of the texture.
        ///@return unsigned int height
        unsigned int getHeight() { return height; };
    private:

        ///@brief The width of the texture.
        unsigned int width;

        ///@brief The height of the texture.
        unsigned int height;
};
#endif