#ifndef CUBE_H
#define CUBE_H

#include <string>

#include <GL/glew.h>

class Cube
{
	public:
        Cube();
		virtual ~Cube();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };
		GLuint getTexture() { return texture; };

		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint texture;

		unsigned int _width;
		unsigned int _height;
};

#endif /* CUBE_H */
