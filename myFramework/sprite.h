#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>

class Sprite
{
	public:
		Sprite(const std::string& _imagepath);
		virtual ~Sprite();

		GLuint getTexture() { return texture; };
		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

	private:
		GLuint loadTGA(const std::string& _imagepath);

		GLuint texture;
		GLuint vertexbuffer;
		GLuint uvbuffer;

		unsigned int width;
		unsigned int height;
};

#endif /* SPRITE_H */
