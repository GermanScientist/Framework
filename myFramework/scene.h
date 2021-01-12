#ifndef SCENE_H
#define SCENE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

class Scene
{
public:
	Scene();
	virtual ~Scene();
	void update(float _deltaTime);

    void run() { isRunning = true; };
    void exit() { isRunning = false; };

    bool getIsRunning() { return isRunning; };

private:

    bool isRunning;
};

#endif /* SCENE_H */