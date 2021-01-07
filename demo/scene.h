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

class Scene
{
public:
	Scene(Renderer* _renderer);
	virtual ~Scene();
	void update(float _deltaTime);

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
};

#endif /* SCENE_H */