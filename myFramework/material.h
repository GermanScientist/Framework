#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <cstdio>

#include <GL/glew.h>

#include <myFramework/textureloader.h>

class Material
{
	public:
		Material();
		virtual ~Material();

		GLuint getTexture() { return texture; };
		GLuint getWidth() { return textureloader->getWidth(); };
		GLuint getHeight() { return textureloader->getHeight(); };

		// Load a .BMP file using our custom loader
		void loadCustomBMP(const char* _imagepath) { texture = textureloader->loadCustomBMP(_imagepath); };

		// Load a .DDS file using GLFW's own loader
		void loadDDS(const char* _imagepath) { texture = textureloader->loadDDS(_imagepath); };

		// Load a .DDS file using GLFW's own loader
		void loadTGA(const std::string& _imagepath) { texture = textureloader->loadTGA(_imagepath); };

	private:
		GLuint texture;
		Textureloader* textureloader;
};

#endif /* MATERIAL_H */