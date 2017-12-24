#include "MonsterController.h"

MonsterController::MonsterController(GameObject * i_pGameObject):
gameObject (i_pGameObject)
{
}

MonsterController::MonsterController(const MonsterController & i_other) {//copy constructor
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;
}
MonsterController & MonsterController::operator=(const MonsterController & i_other) {//assigment operator
	if (gameObject) {
		delete gameObject;
	}
	GameObject * mGameObject = new GameObject();
	*mGameObject = *i_other.gameObject;
	gameObject = mGameObject;
	return *this;
}
MonsterController::MonsterController(MonsterController && i_other):
gameObject(i_other.gameObject)
{//move copy constructor
	i_other.gameObject = nullptr;
}
MonsterController & MonsterController::operator=(MonsterController && i_other) {//move assigment operator
	std::swap(gameObject, i_other.gameObject);
	return *this;
}
void MonsterController::setGameObject(GameObject *i_pObject) {
	gameObject = i_pObject;
}

GameObject * MonsterController::getGameObject() const{
	return gameObject;
}
void MonsterController:: updateGameObject() {
	Vector2D dir(1, 0);
	gameObject->setPosition(gameObject->getPosition() + dir);
}

MonsterController:: ~MonsterController() {
	delete gameObject;
}