#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <myFramework/sprite.h>
#include <myFramework/cube.h>

class Renderer
{
	public:
		Renderer(unsigned int _width, unsigned int _height);
		virtual ~Renderer();

		void renderSprite(Sprite* _sprite, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rot);
        void renderCube(Cube* _cube, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rot);
		GLFWwindow* getWindow() { return window; };

		unsigned int getWidth() { return windowWidth; };
		unsigned int getHeight() { return windowHeight; };

		float updateDeltaTime();

	private:
		int initialize();

		GLFWwindow* window;
		unsigned int windowWidth;
		unsigned int windowHeight;

		GLuint loadShaders(
			const std::string& vertex_file_path,
			const std::string& fragment_file_path
		);

		GLuint programID;

		glm::mat4 projectionMatrix;
};

#endif /* RENDERER_H */