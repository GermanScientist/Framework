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
		GLuint getLightID() { return LightID; };

	private:
		GLuint loadShaders(const std::string& _vertex_file_path, const std::string& _fragment_file_path);

		GLuint programID;
		GLuint LightID;
};

#endif /* SHADER_H */