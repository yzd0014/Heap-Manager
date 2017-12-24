#pragma once
#include "Source/Math/Vector2D.h"
class GameObject {
public:
	GameObject();
	GameObject(const char * i_pName, const Vector2D &i_position, uint8_t i_life);//constructor
	GameObject(const GameObject &i_ther);//copy constructor
	GameObject & operator=(const GameObject &i_other);// assignment operator
	GameObject(GameObject &&i_other);//move copy constructor
	GameObject & operator=(GameObject &&i_other);//move assignment operator
	inline Vector2D getPosition() const;
	inline void setPosition(const Vector2D &i_position);
	inline void setName(const char *i_pName);
	inline char * getName() const;
	inline unsigned int getID() const;
	inline void setID(unsigned int i_ID);
	inline uint8_t getLife();
	inline void setLife(uint8_t i_life);
	~GameObject();
private: 
	Vector2D position;
	unsigned int ID;
	static unsigned int IDPool;
	uint8_t life;
	char * pName;
};

#include "GameObject-inl.h"