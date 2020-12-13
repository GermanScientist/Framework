#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class Textureloader {
    public:
        Textureloader(const char* _imagepath);
        virtual ~Textureloader();

        // Load a .BMP file using our custom loader
        GLuint loadCustomBMP();

        // Load a .DDS file using GLFW's own loader
        GLuint loadDDS();
    private:
        const char* imagepath;
};


#endif