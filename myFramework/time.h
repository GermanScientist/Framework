#ifndef TIME_H
#define TIME_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Time
{
	public:
		Time();
		virtual ~Time();

		static float getDeltaTime();

	private:
};

#endif /* TIME_H */