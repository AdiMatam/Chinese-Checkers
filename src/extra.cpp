#include "pch.hpp"
#include "checkers.hpp"

// WHEN BOARD IS ROTATED, NEED TO ADJUST THE SELECTED "POINT"
// OTHERWISE, THE RAW (X, Y) WILL NOT MATCH WITH THE (X, Y) OF CORRECT SLOT 
void ChineseCheckers::normalize(float* x, float* y) {
	sf::Vector2f pos = m_Rotater.getInverse().transformPoint(*x, *y);
	*x = pos.x;
	*y = pos.y;
}

// PRE-CONDITION:
//		S1: SLOT TO BE MOVED
//		S2: EMPTY SLOT (TRANSPARENT COLOR)
ChineseCheckers::MoveType ChineseCheckers::validateMove(Slot* s1, Slot* s2) {
	sf::Vector2f pos1 = s1->getPosition();
	sf::Vector2f pos2 = s2->getPosition();

	// absolute distance between 2 points. 
	float distance = sqrtf(powf(pos1.y - pos2.y, 2) + powf(pos1.x - pos2.x, 2));
	if (distance <= 4 * RADIUS)
		return MoveType::SINGLE;

	// midpoint
	float midX = (pos1.x + pos2.x) / 2.f;
	float midY = (pos1.y + pos2.y) / 2.f;
	Slot* midPoint = findSlot(midX, midY);
	if (midPoint != nullptr && !midPoint->isEmpty()) // jumping over a piece
		return MoveType::MULTIPLE;

	return MoveType::NOHOPE;
}

// USE BINARY SEARCH TO DETERMINE WHICH SLOT (IN ARRAY) WAS SELECTED
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

// PRINT MESSAGES TO HIGHLIGHT "MISTAKES" IN GAMEPLAY
void ChineseCheckers::showErrors(Slot* clicked) {
	if (m_Selected == nullptr) {
		printf("INVALID SELECTION: ");
		if (clicked->isEmpty()) 
			printf("NO PIECE HERE\n");
		else 
			printf("OPPONENT PIECE HERE\n");
	}
	else
		printf("INVALID MOVE - MUST (MOVE BY 1) OR (JUMP OVER PIECE)\n");
}

void ChineseCheckers::undo() {
	if (m_MoveStack.empty()) {
		printf("NO MOVES HAVE BEEN MADE!\n");
		return;
	}
	auto [start, end] = m_MoveStack.top();
	m_MoveStack.pop();

	start->setFillColor(end->getFillColor());
	end->setFillColor(sf::Color::Transparent);
	
	--m_CurrentPlayer %= m_PlayerCount;
	printf("MOVE UNDONE\n\nPLAYER %d / %d:\n", m_CurrentPlayer + 1, m_PlayerCount);

}

//void ChineseCheckers::save(const std::string& filepath) {
//	printf("Saving, to be implemented...\n");
//}