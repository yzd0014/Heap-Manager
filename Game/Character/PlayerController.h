#pragma once
#include "Engine.h"
class PlayerController : public GameObjectController {
public:
	PlayerController(GameObject * i_pGameObject);
	PlayerController(const PlayerController & i_other);//copy constructor
	PlayerController & operator = (const PlayerController & i_i_other);//assignment operator
	PlayerController(PlayerController && i_other);//move copy constructor
	PlayerController & operator = (PlayerController && i_i_other);//move assignment operator
	void setGameObject(GameObject *i_pObject) override;
	GameObject *getGameObject() const override;
	void updateGameObject() override;
	void getDirectionFromUser(char userInput);
	~PlayerController() override;
private:
	GameObject *gameObject = nullptr;
	Vector2D dir;//player's move displacement
};