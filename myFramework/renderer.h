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

class Renderer
{
	public:
		Renderer(unsigned int _width, unsigned int _height);
		virtual ~Renderer();

		void renderSprite(Sprite* _sprite);
        void renderCube(Cube* _cube, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rotX, float _rotY, float _rotZ);
		void renderModel(Model* _model, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rotX, float _rotY, float _rotZ);
		GLFWwindow* getWindow() { return window; };

		unsigned int getWidth() { return windowWidth; };
		unsigned int getHeight() { return windowHeight; };

	private:
		int initialize();

		GLFWwindow* window;
		unsigned int windowWidth;
		unsigned int windowHeight;
};

#endif /* RENDERER_H */