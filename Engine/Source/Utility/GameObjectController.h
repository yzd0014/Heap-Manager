#pragma once
#include "GameObject.h"
#include "Source/MemoryManagement/HeapManager.h"
class GameObjectController {
public:
	virtual void setGameObject(GameObject *i_pObject) = 0;
	virtual GameObject *getGameObject() const = 0;
	virtual void updateGameObject() = 0;
	virtual ~GameObjectController() = 0;
};