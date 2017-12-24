#include "SmartMonsterController.h"

SmartMonsterController::SmartMonsterController(GameObject *i_pGameObject, const GameObject * i_pFocusObject):
gameObject(i_pGameObject),
focusObject(i_pFocusObject)
{
}
SmartMonsterController::SmartMonsterController(const SmartMonsterController &i_other) {
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;
	
	focusObject = i_other.focusObject;
}
SmartMonsterController &SmartMonsterController:: operator=(const SmartMonsterController &i_other) {
	if (gameObject) {
		delete gameObject;
	}
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;

	focusObject = i_other.focusObject;
	return *this;
}
SmartMonsterController::SmartMonsterController(SmartMonsterController &&i_other):
gameObject (i_other.gameObject),
focusObject (i_other.focusObject)
{
	i_other.gameObject = nullptr;	
}
SmartMonsterController &SmartMonsterController:: operator=(SmartMonsterController &&i_other) {
	std::swap(gameObject, i_other.gameObject);
	std::swap(focusObject, i_other.focusObject);
	return *this;
}
void SmartMonsterController::setGameObject(GameObject *i_pObject) {
	gameObject = i_pObject;
}

GameObject * SmartMonsterController::getGameObject() const {
	return gameObject;
}

void SmartMonsterController::updateGameObject() {
	//assert(gameObject);
	Vector2D dir = focusObject->getPosition() - gameObject->getPosition();
	if (dir.get_x() != 0 || dir.get_y() != 0) {
		dir.normalize();
		gameObject->setPosition(gameObject->getPosition() + dir);
	}
	
}

void SmartMonsterController::setFocusOject(GameObject *i_pObject) {
	focusObject = i_pObject;
}

SmartMonsterController::~SmartMonsterController() {
	delete gameObject;
}