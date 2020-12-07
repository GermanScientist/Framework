#ifndef CUBE_H
#define CUBE_H

#include <string>

#include <GL/glew.h>

class Cube
{
	public:
        Cube();
		virtual ~Cube();

		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint colorbuffer() { return _colorbuffer; };

		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

	private:
		GLuint _vertexbuffer;
		GLuint _colorbuffer;

		unsigned int _width;
		unsigned int _height;
};

#endif /* CUBE_H */
