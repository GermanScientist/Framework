/**
 * @file renderer.h
 *
 * @brief The Renderer header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <myFramework/sprite.h>
#include <myFramework/cube.h>
#include <myFramework/model.h>
#include <myFramework/scene.h>
#include <myFramework/camera.h>

class Renderer
{
	public:
		///@brief Constructor of the Renderer.
		///@param _width The width of the window.
		///@param _height The height of the window.
		Renderer(unsigned int _width, unsigned int _height);

		///@brief Destructor of the Renderer
		virtual ~Renderer();

		///@brief Renders the scene and all the children of the scene.
		///@param _scene The scene that needs to be renderered.
		///@return void
		void renderScene(Scene* _scene);

		///@brief Renders the sprite of an entity in the scene.
		///@param _sprite The sprite that needs to be renderered.
		///@param _modelMatrix The modelmatrix of the entity.
		///@return void
		void renderSprite(Sprite* _sprite, glm::mat4 _modelMatrix);

		///@brief Renders the cube of an entity in the scene.
		///@param _cube The cube that needs to be renderered.
		///@param _modelMatrix The modelmatrix of the entity.
		///@return void
        void renderCube(Cube* _cube, glm::mat4 _modelMatrix);

		///@brief Renders the cube of an entity in the scene.
		///@param _model The model that needs to be renderered.
		///@param _modelMatrix The modelmatrix of the entity.
		///@return void
		void renderModel(Model* _model, glm::mat4 _modelMatrix);

		///@brief Renders the entity and checks whether it has a model, sprite or cube to render.
		///@param _model The entity that needs to be renderered.
		///@return void
		void renderEntity(Entity* _entity);

		///@brief Gets the application window.
		///@return GLFWwindow* window
		GLFWwindow* getWindow() { return window; };


		///@brief Gets the width of the window.
		///@return unsigned int windowWidth
		unsigned int getWidth() { return windowWidth; };

		///@brief Gets the height of the window.
		///@return unsigned int windowHeight
		unsigned int getHeight() { return windowHeight; };

	private:
		///@brief Intializes the renderer and the application window.
		///@return int
		int initialize();

		///@brief The application window.
		GLFWwindow* window;

		///@brief The width of the application window.
		unsigned int windowWidth;

		///@brief The height of the application window.
		unsigned int windowHeight;

		///@brief A local holder for the camera's viewmatrix.
		glm::mat4 viewMatrix;

		///@brief A local holder for the camera's projectionmatrix.
		glm::mat4 projectionMatrix;
};

#endif /* RENDERER_H */