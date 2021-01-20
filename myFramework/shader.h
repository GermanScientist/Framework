#ifndef SHADER_H
#define SHADER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
	public:
		Shader();
		virtual ~Shader();

		//Load 2D shaders
		void load2DShaders();

		//Load 3D shaders
		void load3DShaders();

		GLuint getProgramID() { return programID; };
		GLuint getLightID() { return lightID; };
		GLuint getMatrixID() { return matrixID; };
		GLuint getViewMatrixID() { return viewMatrixID; };
		GLuint getModelMatrixID() { return modelMatrixID; };

		GLuint getTextureID() { return textureID; };
		GLuint getVertexPositionID() { return vertexPositionID; };

		GLuint getVertexPositionModelspaceID() { return vertexPositionModelspaceID; };
		GLuint getVertexUVID() { return vertexUVID; };
		GLuint getVertexNormalModelspaceID() { return vertexNormalModelspaceID; };

	private:
		GLuint loadShaders(const std::string& _vertex_file_path, const std::string& _fragment_file_path);

		GLuint programID;
		GLuint lightID;
		GLuint matrixID;
		GLuint viewMatrixID;
		GLuint modelMatrixID;

		GLuint textureID;
		GLuint vertexPositionID;
		
		GLuint vertexPositionModelspaceID;
		GLuint vertexUVID;
		GLuint vertexNormalModelspaceID;
};

#endif /* SHADER_H */