#pragma once

#include <vector>
#include <string>

class GameObject
{
    GameObject(std::wstring iname, Game *igame);

    virtual void update(float) = 0;
    virtual void render(float) = 0;
    virtual void renderHUD(float) = 0;
    virtual void renderAudio(float) = 0;
    virtual void shutdown() = 0;
    virtual ~GameObject() = 0;

    GameObject *GameObject::getParent();
    GameObject *getGameObject(std::wstring name);

    template <typename T>
    T *getGameObject();

    template <typename T>
    std::vector<T *> *getGameObjects(std::vector<T *> *result);

    template <typename T>
    T *addGameObject(T *object);

private:
    Game *game;
    std::wstring name;
    bool isActive;
    GameObject *parent;
    std::vector<GameObject *> gameObjects;
};