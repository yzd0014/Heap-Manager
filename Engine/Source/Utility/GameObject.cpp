#include "GameObject.h"
#include "Engine.h"

unsigned int GameObject::IDPool = 0;
GameObject::GameObject() {}
GameObject::GameObject(const char * i_pName, const Vector2D &i_position, uint8_t i_life):
position(i_position),
ID(IDPool),
life(i_life),
pName(dupstring(i_pName ? i_pName : "Unnamed"))
{//constructor
	IDPool++;
}

GameObject::GameObject(const GameObject &i_other):
position (i_other.position),
ID(i_other.ID),
life(i_other.life),
pName(dupstring(i_other.pName ? i_other.pName : "Unnamed"))
{//copy constructor
	IDPool++;
}

GameObject & GameObject::operator=(const GameObject &i_other) {//assignment operator
	if (pName) {
		delete[] pName;
	}
	ID = i_other.ID;
	pName = dupstring(i_other.pName ? i_other.pName : "Unnamed");
	position = i_other.position;
	life = i_other.life;
	return *this;
}

GameObject::GameObject(GameObject &&i_other):
position(i_other.position),
ID(i_other.ID),
life(i_other.life),
pName(i_other.pName)
{//move copy constructor
	i_other.pName = nullptr;
}
GameObject & GameObject::operator=(GameObject &&i_other) {//move assignment operator
	std::swap(ID, i_other.ID);
	std::swap(pName, i_other.pName);
	std::swap(position, i_other.position);
	std::swap(life, i_other.life);
	return *this;
}
GameObject::~GameObject() {
	if (pName) {
		delete[] pName;
	}
}

