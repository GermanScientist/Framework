#ifndef RUNNER_H
#define RUNNER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/renderer.h>
#include <myFramework/camera.h>

#include "demo/myScene.h"

class Runner
{
	public:
		Runner();
		virtual ~Runner();

		void run(MyScene* _scene);
		Renderer* getRenderer() { return renderer; }

		float getDeltaTime();

	private:
		Renderer* renderer;
};

#endif /* RUNNER_H */