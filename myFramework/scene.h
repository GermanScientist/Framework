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

class Scene
{
    public:
	    Scene();
	    virtual ~Scene();
	    void update(float _deltaTime);

        void run() { isRunning = true; };
        void exit() { isRunning = false; };

        bool getIsRunning() { return isRunning; };

        std::vector<Entity*> getEntities() { return entities; };

        void addEntity(Entity* _entity);
        void removeEntity(Entity* _entity);

        Camera* getCamera() { return camera;; };

    private:

        bool isRunning;
        Camera* camera;

    protected:
        std::vector<Entity*> entities;
};

#endif /* SCENE_H */