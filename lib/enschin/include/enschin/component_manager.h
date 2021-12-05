#pragma once

#include "game_object.h"

class GameObject;
struct ComponentManager{
private:
    std::vector<GameObject*> gameObjects;
public:
    ~ComponentManager();
    void addGameObject(GameObject* gameObject);
    void removeDeadObjects();
    GameObject& getGameObject(int index){ return *gameObjects.at(index); }
    std::vector<GameObject*>& getGameObjects(){ return gameObjects; }
    std::vector<GameObject*> getGameObjects(std::string filter);
};