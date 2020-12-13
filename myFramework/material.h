#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <cstdio>

#include <GL/glew.h>

#include <myFramework/textureloader.h>

class Material
{
	public:
		Material(const char* _imagepath);
		virtual ~Material();

		GLuint getTexture() { return texture; };
		/*Textureloader* getTextureloader() { return textureloader; };*/

		// Load a .BMP file using our custom loader
		void loadCustomBMP() { texture = textureloader->loadCustomBMP(); };

		// Load a .DDS file using GLFW's own loader
		void loadDDS() { texture = textureloader->loadDDS(); };

	private:
		GLuint texture;
		Textureloader* textureloader;
};

#endif /* MATERIAL_H */