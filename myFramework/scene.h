#ifndef SCENE_H
#define SCENE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>
#include <algorithm>
#include <myFramework/entity.h>
#include <myFramework/sprite.h>
#include <myFramework/cube.h>
#include <myFramework/model.h>

#include <myFramework/camera.h>

class Scene : public Entity
{
    public:
	    Scene();
	    virtual ~Scene();
	    void updateEntity(Entity* _entity, float _deltaTime);

        void run() { isRunning = true; };
        void exit() { isRunning = false; };

        bool getIsRunning() { return isRunning; };

        Camera* getCamera() { return camera;; };

    private:

        bool isRunning;
        Camera* camera;
};

#endif /* SCENE_H */