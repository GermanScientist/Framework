/**
 * @file shader.h
 *
 * @brief The Shader header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

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
		///@brief Constructor of the Shader.
		Shader();

		///@brief Destructor of the Shader.
		virtual ~Shader();

		///@brief Loads the shaders for 2D entities/objects.
		///@return void
		void load2DShaders();

		///@brief Loads the shaders for 3D entities/objects.
		///@return void
		void load3DShaders();

		///@brief Loads the shaders for 3D entities/objects.
		///@return void
		void loadShadowmap();

		///@brief Gets the program ID.
		///@return GLuint programID
		GLuint getProgramID() { return programID; };

		///@brief Gets the light ID.
		///@return GLuint lightID
		GLuint getLightID() { return lightID; };

		///@brief Gets the matrix ID.
		///@return GLuint matrixID
		GLuint getMatrixID() { return matrixID; };

		///@brief Gets the viewmatrix ID.
		///@return GLuint viewMatrixID
		GLuint getViewMatrixID() { return viewMatrixID; };

		///@brief Gets the modelmatrix ID.
		///@return GLuint modelMatrixID
		GLuint getModelMatrixID() { return modelMatrixID; };

		///@brief Gets the texture ID.
		///@return GLuint textureID
		GLuint getTextureID() { return textureID; };
		
		///@brief Gets the vertex position ID.
		///@return GLuint vertexPositionID
		GLuint getVertexPositionID() { return vertexPositionID; };

		///@brief Gets the vertex position modelspace ID.
		///@return GLuint vertexPositionModelspaceID
		GLuint getVertexPositionModelspaceID() { return vertexPositionModelspaceID; };

		///@brief Gets the vertex UV ID.
		///@return GLuint vertexUVID
		GLuint getVertexUVID() { return vertexUVID; };

		///@brief Gets the vertex normal modelspace ID.
		///@return GLuint getVertexNormalModelspaceID
		GLuint getVertexNormalModelspaceID() { return vertexNormalModelspaceID; };

		//SHADOWMAPS
        GLuint getDepthBiasID() { return depthBiasID; };
        GLuint getShadowMapID() { return shadowMapID; };
        GLuint getDirLightID() { return dirLightID; };

        GLuint getDepthProgramID() { return depthProgramID; };
        GLuint getDepthMatrixID() { return depthMatrixID; };
        GLuint getDepthVertexPositionModelspaceID() { return depthVertexPositionModelspaceID; };

	private:
		///@brief Loads the shaders.
		///@param _vertex_file_path The file location of the vertexshader.
		///@param _fragment_file_path The file location of the fragmentshader.
		///@return GLuint programID
		GLuint loadShaders(const std::string& _vertex_file_path, const std::string& _fragment_file_path);

		///@brief The ID of the program.
		GLuint programID;

		///@brief The ID of the light.
		GLuint lightID;

		///@brief The ID of the matrix.
		GLuint matrixID;

		///@brief The ID of the viewmatrix.
		GLuint viewMatrixID;

		///@brief The ID of the modelmatrix.
		GLuint modelMatrixID;

		///@brief The ID of the texture.
		GLuint textureID;

		///@brief The ID of the vertex position.
		GLuint vertexPositionID;
		
		///@brief The ID of the vertex position modelspace.
		GLuint vertexPositionModelspaceID;

		///@brief The ID of the vertex UV.
		GLuint vertexUVID;

		///@brief The ID of the vertex normal modelspace.
		GLuint vertexNormalModelspaceID;

        //SHADOWMAPS
        GLuint depthBiasID;
        GLuint shadowMapID;
        GLuint dirLightID;

        GLuint depthProgramID;
        GLuint depthMatrixID;
        GLuint depthVertexPositionModelspaceID;
};

#endif /* SHADER_H */