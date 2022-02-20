#include "gameobject.h"

template<typename T>
T *GameObject::getGameObject()
{
  std::vector<GameObject *>::iterator result = std::find_if(gameObjects.begin(), gameObjects.end(), [](const auto& object)
  {
    return dynamic_cast<T*>(object);
  });

  if(result != gameObjects.end())
    return dynamic_cast<T*>(*result);
  else
    return nullptr;
}

template<typename T>
T *GameObject::addGameObject(T *object)
{
  if(!object)
    return nullptr;

  gameObjects.push_back(object);
  object->parent = this;

  return object;
}

GameObject::GameObject(std::wstring iname, Game *igame)
: name{iname}, game{igame}, isActive{true}, parent{nullptr}
{
}

GameObject *GameObject::getParent()
{
  return parent;
}
