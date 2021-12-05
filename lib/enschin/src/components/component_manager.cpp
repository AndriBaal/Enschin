#include <enschin/component_manager.h>

ComponentManager::~ComponentManager() {
    for (auto e : gameObjects)
        delete e;
    gameObjects.clear();
}

void ComponentManager::addGameObject(GameObject *gameObject) {
    gameObjects.push_back(gameObject);
}

void ComponentManager::removeDeadObjects() {
    std::vector<GameObject*>::iterator it = gameObjects.begin();
    while(it != gameObjects.end()) {
        if(!(*it)->isAlive()) {
            it = gameObjects.erase(it);
            delete (*it);
        }
        else ++it;
    }
}

std::vector<GameObject*> ComponentManager::getGameObjects(std::string gameObjectName) {
    std::vector<GameObject*> filteredObjects;
    for (auto& g : gameObjects)
        if (g->getName() == gameObjectName)
            filteredObjects.push_back(g);
    return filteredObjects;
}