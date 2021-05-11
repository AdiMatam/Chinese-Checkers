#include "pch.hpp"
#include "helpers.hpp"

class Slot : public sf::CircleShape {
private:
	int m_Owner;
public:
	Slot(float x, float y, int owner);
	int getOwner();
	void setOwner(int owner);
private:
	void config();
};