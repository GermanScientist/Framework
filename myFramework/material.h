#ifndef MATERIAL_H
#define MATERIAL_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

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

		//Load a .BMP file using our custom loader
		void loadCustomBMP(const char* _imagepath) { texture = textureloader->loadCustomBMP(_imagepath); };

		//Load a .DDS file using GLFW's own loader
		void loadDDS(const char* _imagepath) { texture = textureloader->loadDDS(_imagepath); };

		//Load a .DDS file using GLFW's own loader
		void loadTGA(const std::string& _imagepath) { texture = textureloader->loadTGA(_imagepath); };

		//Load 2D shaders
		void load2DShaders();

		//Load 3D shaders
		void load3DShaders();

		GLuint getProgramID() { return programID; };

	private:
		GLuint texture;
		Textureloader* textureloader;

		GLuint loadShaders(const std::string& _vertex_file_path, const std::string& _fragment_file_path);

		GLuint programID;
};

#endif /* MATERIAL_H */