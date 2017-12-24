#pragma once
#include "Engine.h"
class MonsterController : public GameObjectController {
public:
	MonsterController(GameObject * i_pGameObject);
	MonsterController(const MonsterController & i_other);//copy constructor
	MonsterController & operator=(const MonsterController & i_other);//assigment operator
	MonsterController(MonsterController && i_other);//move copy constructor
	MonsterController & operator=(MonsterController && i_other);//move assigment operator
	void setGameObject(GameObject *i_pObject) override;
	GameObject * getGameObject() const override;
	void updateGameObject() override;
	~MonsterController() override;
private:
	GameObject *gameObject;
};