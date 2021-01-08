#ifndef SCENE_H
#define SCENE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/renderer.h>
#include <myFramework/sprite.h>
#include <myFramework/cube.h>
#include <myFramework/time.h>

class Scene
{
public:
	Scene(Renderer* _renderer);
	virtual ~Scene();
	void update();

    void run() { isRunning = true; };
    void exit() { isRunning = false; };

    bool getIsRunning() { return isRunning; };

private:
    Renderer* renderer;

    Cube* cube;
    Model* cubeModel;
    Model* ballModel;
    Model* houseModel;

    Sprite* uvTemplate;
    Sprite* cubeMap;
    Sprite* ballMap;
    Sprite* houseMap;

    bool isRunning;
};

#endif /* SCENE_H */