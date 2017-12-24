#pragma once
#include "Engine.h"
class SmartMonsterController : public GameObjectController {
public:
	SmartMonsterController(GameObject *i_pGameObject, const GameObject * i_pFocusObject);
	SmartMonsterController(const SmartMonsterController &i_other);
	SmartMonsterController & operator=(const SmartMonsterController &i_other);
	SmartMonsterController(SmartMonsterController &&i_other);
	SmartMonsterController & operator=(SmartMonsterController &&i_other);
	void setGameObject(GameObject *i_pObject) override;
	GameObject *getGameObject() const override;
	void updateGameObject() override;
	void setFocusOject(GameObject *i_pObject);
	~SmartMonsterController() override;
private:
	GameObject *gameObject;
	const GameObject *focusObject;
};