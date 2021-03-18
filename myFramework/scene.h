/**
 * @file scene.h
 *
 * @brief The Scene header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

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
#include <myFramework/model.h>

#include <myFramework/camera.h>

class Scene : public Entity
{
    public:
        ///@brief Constructor of the Scene.
	    Scene();

        ///@brief Destructor of the Scene.
	    virtual ~Scene();

        ///@brief Calls the update function for the entity and it's children.
        ///@param _entity The entity that needs to be updated.
        ///@param _deltaTime The time that's passed since the last update.
        ///@return void
	    void updateEntity(Entity* _entity, float _deltaTime);

        ///@brief Sets isRunning to true.
        ///@return void
        void run() { isRunning = true; };

        ///@brief Sets isRunning to false to stop running the scene.
        ///@return void
        void exit() { isRunning = false; };

        ///@brief Gets the isRunning boolean.
        ///@return bool isRunning
        bool getIsRunning() { return isRunning; };

        ///@brief Gets the camera of the scene.
        ///@return Camera* camera
        Camera* getCamera() { return camera;; };

    private:

        ///@brief Checks whether the scene is running or not.
        bool isRunning;

        ///@brief The camera of the scene.
        Camera* camera;
};

#endif /* SCENE_H */