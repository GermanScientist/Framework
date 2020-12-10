#ifndef CUBE_H
#define CUBE_H

#include <string>

#include <GL/glew.h>

class Cube
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };
		GLuint getTexture() { return texture; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint texture;
		GLuint vertexArrayID;

		unsigned int width;
		unsigned int height;
};

#endif /* CUBE_H */
