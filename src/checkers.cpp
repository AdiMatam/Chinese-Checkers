#include "pch.hpp"
#include "checkers.hpp"
#define CC ChineseCheckers
//using CC = ChineseCheckers

CC::ChineseCheckers(sf::RenderWindow* window, int playerCount) 
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0), m_Selected(nullptr),
		m_GameOver(false)
{
	std::cout << "Starting Game" << std::endl;
	config();
	createBoard();
}

CC::~ChineseCheckers() {
	std::cout << "Ending Game" << std::endl;
}

void CC::nextTurn() {
	if (++m_CurrentPlayer >= m_PlayerCount)
		m_CurrentPlayer = 0;
}

void CC::rotateBoard() {
	m_Rotter.rotate(360.f / m_PlayerCount, HALF, HALF);
}

void CC::handleEvent(sf::Event& ev) {
	if (mousePressed(ev, sf::Mouse::Left)) {
		Slot* current = findSlot(ev.mouseButton.x, ev.mouseButton.y);
		if (current->isMine(m_CurrentPlayer, m_PlayerCount)) {
			m_Selected = current;
		}
		else if (current->isEmpty()) {
			// move
		}
	}
}

int CC::checkWin() {
	int len = 6 / m_PlayerCount; // 3
	sf::Color* mine = (sf::Color*)alloca(sizeof(sf::Color) * len);
	
	getMyColors(m_CurrentPlayer, m_PlayerCount, mine, len);

	for (Slot& s : m_Slots) {
		if (
			!arrContains(s.getFillColor(), mine, len) and
			s.getFillColor() != s.getGoalColor()
		)
			return -1;
	}
	m_GameOver = true;
	return m_CurrentPlayer;
}

bool CC::isGameOver() {
	return m_GameOver;
}

CC::MoveType CC::validateMove() {
	
}

Slot* CC::findSlot(float wantX, float wantY) {
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


