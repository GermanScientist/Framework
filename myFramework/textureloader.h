#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <iostream>
#include <cstdio>

#include <GL/glew.h>

class Textureloader {
    public:
        Textureloader();
        virtual ~Textureloader();

        //Load a .BMP file
        GLuint loadCustomBMP(const char* _imagepath);

        //Load a DDS file
        GLuint loadDDS(const char* _imagepath);

        //Load a TGA file
        GLuint loadTGA(const std::string& _imagepath);

        unsigned int getWidth() { return width; };
        unsigned int getHeight() { return height; };
    private:
        unsigned int width;
        unsigned int height;
};
#endif