#include "pch.hpp"
#include "checkers.hpp"

#define CC ChineseCheckers

CC::ChineseCheckers(sf::RenderWindow* window, int playerCount)
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0), 
	m_Selected(nullptr), m_GameOver(false), m_EnableMouse(true)
{
	m_CurrentMove.reset();
	printf("STARTING GAME\n\nPLAYER %d / %d:\n", m_CurrentPlayer + 1, m_PlayerCount);
	config();
	Slot::s_PlayerColors = m_PlayerColors;
	createBoard();
}

CC::~ChineseCheckers() {
	printf("\nENDING GAME\n");
}

// WHEM MOUSE-CLICKED, WHAT SHOULD HAPPEN IN GAME?
void CC::processClick(float x, float y) {
	normalize(&x, &y);
	Slot* clicked = findSlot(x, y);
	if (clicked == nullptr) return;

	if (clicked->isMine(m_CurrentPlayer, m_PlayerCount) && m_EnableMouse) {
		m_CurrentMove.start = clicked;
		selector(clicked);
	}
	else if (clicked->isEmpty() && m_Selected != nullptr)
		move(clicked);
	else
		showErrors(clicked);
}

void CC::selector(Slot* clicked) {
	printf("VALID SELECTION\n");
	if (m_Selected != nullptr)
		m_Selected->unpick();
	m_Selected = clicked;
	m_Selected->pick();
}

void CC::move(Slot* clicked) {
	MoveType type = validateMove(m_Selected, clicked);
	if (type == MoveType::NOHOPE) {
		printf("INVALID MOVE - MUST (MOVE BY 1) OR (JUMP OVER PIECE)\n");
		return;
	}
	printf("VALID MOVE\n");
	// how piece movement works. circle position unchaged, instead, colors are swapped
	clicked->setFillColor(m_Selected->getFillColor());
	clicked->unpick();

	m_Selected->setFillColor(sf::Color::Transparent);
	m_Selected->unpick();

	m_CurrentMove.end = clicked;
	
	if (type == MoveType::SINGLE) {
		m_Selected = nullptr;
		nextTurn();
	}
	else {
		// multi-move. in this situation, player is not allowed to select another piece
		// hence, manual selection (by mouse) is disabled
		m_EnableMouse = false;
		selector(clicked);
	}
}

// FOR A VICTORY, EVERY PIECE THAT BELONGS TO A GIVEN PLAYER MUST BE IN THE "DESTINATION"
int CC::checkWin() {
	int len = 6 / m_PlayerCount;
	getMyColors(m_CurrentPlayer, m_PlayerCount, m_PlayerColors, len);
	for (Slot& s : m_Slots) {
		/* if a slot does not belong to current player 
		AND its current color doesn't match the color it should be (at end), no win yet */
		if (
			!arrContains(s.getFillColor(), m_PlayerColors, len) and
			s.getFillColor() != s.getGoalColor()
			)
			return -1;
	}
	m_GameOver = true;
	printf("Game Over -> Player %d won the game\n", m_CurrentPlayer);
	return m_CurrentPlayer;
}

bool CC::isOver() {
	return m_GameOver;
}

void ChineseCheckers::nextTurn() {
	m_MoveStack.push(std::move(m_CurrentMove));
	m_CurrentMove.reset();

	checkWin();
	m_EnableMouse = true;
	++m_CurrentPlayer %= m_PlayerCount;
	printf("\nPlayer %d / %d:\n", m_CurrentPlayer + 1, m_PlayerCount);
}

// MULTI MOVE HANDLER. PREVENT PLAYER FROM "SKIPPING A TURN"
bool ChineseCheckers::movedAtAll() {
	if (!m_EnableMouse) {
		if (m_Selected != nullptr)
			m_Selected->unpick();
		return true;
	}
	return false;
}