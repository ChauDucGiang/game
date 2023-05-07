#pragma once
#include "PlayScene.h"
#include "Scene.h"

class SceneManager
{
public:
    static SceneManager* getInstance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new SceneManager();
        }
        return pInstance;
    }

    void createScene(Scene* scene)
    {

        if (scene)
        {
            if (pCurrentScene)
                delete pCurrentScene;
            pCurrentScene = scene;
        }
    }

    //chuyen Scene voi hieu ung ngau nhien

    //kiem tra xem transition finish chua
    void updateWithEffect()
    {
        this->pInstance->createScene(destScene);
        isTransitioning = false;
    }

    bool isSceneTransitioning()
    {
        return isTransitioning;
    }

    Scene* getCurrentScene() { return pCurrentScene; }
private:
    SceneManager()
    {
        pCurrentScene = NULL;
        isTransitioning = false;
    }
    static SceneManager* pInstance;
    Scene* pCurrentScene;
    Scene* destScene; //dung do transition
    bool isTransitioning;
};