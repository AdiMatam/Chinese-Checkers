#include "pch.hpp"
#include "checkers.hpp"

void ChineseCheckers::correct(float* x, float* y) {
	auto [a, b] = m_Rotater.getInverse().transformPoint(*x, *y);
	*x = a;
	*y = b;
}

ChineseCheckers::MoveType ChineseCheckers::validateMove(Slot* s1, Slot* s2) {
	sf::Vector2f s1pos = s1->getPosition();
	sf::Vector2f s2pos = s2->getPosition();

	float distance = sqrtf(powf(s1pos.y - s2pos.y, 2) + powf(s1pos.x - s2pos.x, 2));
	if (distance <= 4 * RADIUS)
		return MoveType::SINGLE;

	// MIDPOINT
	float midX = (s1pos.x + s2pos.x) / 2.f;
	float midY = (s1pos.y + s2pos.y) / 2.f;
	Slot* midPoint = findSlot(midX, midY);
	if (midPoint != nullptr && !midPoint->isEmpty())
		return MoveType::MULTIPLE;

	return MoveType::NOHOPE;
}

Slot* ChineseCheckers::findSlot(float wantX, float wantY) {
	int low = 0;
	int mid = 0;
	int high = m_Slots.size() - 1;
	int currentY = 0;
	const float RADIUS = m_Slots[0].getRadius();

	while (low <= mid) {
		mid = (low + high) / 2;
		currentY = m_Slots[mid].getPosition().y;
		if (std::abs(currentY - wantY) <= RADIUS)
			break;
		else if (currentY > wantY)
			high = mid - 1;
		else
			low = mid + 1;
	}
	for (int i = low; i <= high; i++) {
		if (m_Slots[i].clicked(wantX, wantY))
			return &m_Slots[i];
	}
	return nullptr;
}

