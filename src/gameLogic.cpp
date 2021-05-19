#include "pch.hpp"
#include "checkers.hpp"

#define CC ChineseCheckers

CC::ChineseCheckers(sf::RenderWindow* window, int playerCount) 
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0), m_Selected(nullptr),
		m_GameOver(false), m_EnableMouse(true)
{
	std::cout << "Starting Game" << std::endl;
	config();
	createBoard();
}

CC::~ChineseCheckers() {
	std::cout << "Ending Game" << std::endl;
}

void CC::processClick(float x, float y, bool force) {
	Slot* clicked = findSlot(x, y);
	if (clicked == nullptr) return;

	if ((clicked->isMine(m_CurrentPlayer, m_PlayerCount) && m_EnableMouse) || force)
		selector(clicked);
	else if (clicked->isEmpty() && m_Selected != nullptr)
		move(clicked);
}

void CC::selector(Slot* clicked) {
	if (m_Selected != nullptr)
		m_Selected->unpick();
	clicked->pick();
	m_Selected = clicked;
}

void CC::move(Slot* clicked) {
	MoveType type = validateMove(clicked, m_Selected);
	if (type == MoveType::NOHOPE)
		return;
	bool ender = type == MoveType::SINGLE;
	if (m_EnableMouse || !ender) {
		clicked->setFillColor(m_Selected->getFillColor());
		clicked->unpick();

		m_Selected->setFillColor(sf::Color::Transparent);
		m_Selected->unpick();

		if (ender) {
			m_Selected = nullptr;
			nextTurn();
		}
		else {
			m_EnableMouse = false;
			auto [x, y] = clicked->getPosition();
			processClick(x, y, true);
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

void ChineseCheckers::nextTurn() {
	m_EnableMouse = true;
	++m_CurrentPlayer %= m_PlayerCount;
}

void ChineseCheckers::rotateBoard() {
	m_Rotter.rotate(360.f / m_PlayerCount, HALF, HALF);
}

bool ChineseCheckers::movedAtAll() {
	if (!m_EnableMouse) {
		if (m_Selected != nullptr)
			m_Selected->unpick();
		return true;
	}
	return false;
}