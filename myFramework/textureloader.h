#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class Textureloader {
    public:
        Textureloader();
        virtual ~Textureloader();

        // Load a .BMP file using our custom loader
        GLuint loadCustomBMP(const char* _imagepath);

        // Load a .DDS file using GLFW's own loader
        GLuint loadDDS(const char* _imagepath);
    private:

};
#endif