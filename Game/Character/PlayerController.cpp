#include "PlayerController.h"

PlayerController::PlayerController(GameObject * i_pGameObject):
gameObject (i_pGameObject)
{	
}

PlayerController::PlayerController(const PlayerController & i_other) {//copy constructor
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;
}
PlayerController & PlayerController::operator=(const PlayerController & i_other) {//assignment operator
	if (gameObject) {
		delete gameObject;
	}
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;
	return *this;
}
PlayerController::PlayerController(PlayerController && i_other):
gameObject(i_other.gameObject)
{//move copy constructor
	i_other.gameObject = nullptr;
}
PlayerController & PlayerController::operator=(PlayerController && i_other) {//move assignment operator
	std::swap(gameObject, i_other.gameObject);
	return *this;
}
void PlayerController::setGameObject(GameObject *i_pObject){
	gameObject = i_pObject;
}
GameObject * PlayerController::getGameObject() const {
	return gameObject;
}

void PlayerController::updateGameObject() {
	gameObject->setPosition(gameObject->getPosition() + dir);
}

void PlayerController::getDirectionFromUser(char userInput) {
	//Vector2D output;
	if (userInput == 'w') {//up
		dir.set_x(0);
		dir.set_y(1);
	}
	else if (userInput == 's') {//down
		dir.set_x(0);
		dir.set_y(-1);
	}
	else if (userInput == 'a') {//left	
		dir.set_x(-1);
		dir.set_y(0);
	}
	else if (userInput == 'd') {//right
		dir.set_x(1);
		dir.set_y(0);
	}
	else if (userInput == 'j') {
		dir.set_x(0);
		dir.set_y(0);
	}
}

PlayerController::~PlayerController() {
	delete gameObject;
}