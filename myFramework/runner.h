/**
 * @file runner.h
 *
 * @brief The Runner header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef RUNNER_H
#define RUNNER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/renderer.h>

#include "demo/myScene.h"
#include <myFramework/scene.h>

class Runner
{
	public:
		///@brief Constructor of the Runner.
		Runner();

		///@brief Constructor of the Runner.
		virtual ~Runner();

		///@brief Runs the specified scene.
		///@param _scene The scene that needs to be run.
		///@return void
		void run(Scene* _scene);

		///@brief Gets the renderer.
		///@return Renderer* renderer
		Renderer* getRenderer() { return renderer; }

		///@brief Calculates and returns the time that's passed since the last update.
		///@return float deltaTime
		float getDeltaTime();

	private:
		///@brief An instance of the Renderer.
		Renderer* renderer;
};

#endif /* RUNNER_H */