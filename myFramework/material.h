/**
 * @file material.h
 *
 * @brief The Material header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/textureloader.h>
#include <myFramework/shader.h>

class Material
{
	public:
		///@brief Constructor of Material.
		Material();

		///@brief Destructor of Material.
		virtual ~Material();

		///@brief Get the shader of the Material.
		///@return shader
		Shader* getShader() { return shader; };

		///@brief Get the texture of the Material.
		///@return shader
		GLuint getTexture() { return texture; };

		///@brief Get the width from the textureloader.
		///@return textureloader->getWidth()
		GLuint getWidth() { return textureloader->getWidth(); };

		///@brief Get the height from the textureloader.
		///@return textureloader->getHeight()
		GLuint getHeight() { return textureloader->getHeight(); };

		///@brief Loads a .BMP file and sets the texture to the loaded image.
		///@param _imagepath The file location of the image the user wants to load.
		///@return void
		void loadCustomBMP(const char* _imagepath) { texture = textureloader->loadCustomBMP(_imagepath); };

		///@brief Loads a .DDS file and sets the texture to the loaded image.
		///@param _imagepath The file location of the image the user wants to load.
		///@return void
		void loadDDS(const char* _imagepath) { texture = textureloader->loadDDS(_imagepath); };

		///@brief Loads a .TGA file and sets the texture to the loaded image.
		///@param _imagepath The file location of the image the user wants to load.
		///@return void
		void loadTGA(const std::string& _imagepath) { texture = textureloader->loadTGA(_imagepath); };

	private:
		///@brief The texture of this material
		GLuint texture;

		///@brief The textureloader for this material
		Textureloader* textureloader;

		///@brief The shader of this material
		Shader* shader;
};

#endif /* MATERIAL_H */