#include "pch.hpp"
#include "checkers.hpp"

ChineseCheckers::ChineseCheckers(sf::RenderWindow* window, int playerCount) 
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0), m_Selected(nullptr)
{
	std::cout << "Starting Game" << std::endl;
	config();
	createBoard();
}

ChineseCheckers::~ChineseCheckers() {
	std::cout << "Ending Game" << std::endl;
}

void ChineseCheckers::nextTurn() {
	++m_CurrentPlayer %= m_PlayerCount;
}

void ChineseCheckers::draw() {
	m_Window->draw(m_Outline);
	for (auto& s : m_Slots)
		s.draw(m_Window, &m_Rotter);
}

void ChineseCheckers::createBoard() {
	m_Slots.reserve(121);
	float X = HALF, Y = HALF;
	// 9 row
	m_Slots.emplace_back(X, Y, 9);
	for (int i = 0; i < 9 / 2; i++) {
		X -= XSTEP;
		m_Slots.emplace_back(X, Y, 9);
		m_Slots.emplace_back(SIZE - X, Y, 9);
	}
	Y -= YSTEP;
	int rows[8] = { 10, 11, 12, 13, 4, 3, 2, 1 };
	for (int row : rows) {
		addSlotRow(Y, row);
		Y -= YSTEP;
	}
	std::sort (
		m_Slots.begin(), m_Slots.end(), 
		[](const Slot& a, const Slot& b) 
		{ return a.getPosition().y < b.getPosition().y; }
	);
}

void ChineseCheckers::rotateBoard() {
	m_Rotter.rotate(360.f / m_PlayerCount, HALF, HALF);
}

bool ChineseCheckers::checkWin() {
	int incr = 6 / m_PlayerCount; // 3
	int index = m_CurrentPlayer * incr; // 0 | 3
	// 2 players - 0,1,2 | 3,4,5
	
	sf::Color* mine = (sf::Color*)alloca(sizeof(sf::Color) * incr);
	for (int i = index; i < index + incr; i++)
		mine[i - index] = COLORS[i];

	auto inArr = [=](const sf::Color& c) {
		return std::find(
			mine, mine + incr, c)
			!= mine + incr;
	};

	for (Slot& s : m_Slots) {
		if (!inArr(s.getFillColor()) 
			and s.getFillColor() != s.getGoalColor()) {
			return false;
		}
	}
	return true;
}

Slot* ChineseCheckers::find(float wantX, float wantY) {
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

void ChineseCheckers::addSlotRow(float Y, int row) {
	int buf;
	if (row == 13)      buf = 2;
	else if (row == 12) buf = 3;
	else if (row == 11) buf = 3;
	else if (row == 10) buf = 4;
	else                buf = 0;

	float X = HALF;
	int current = row;
	if (row % 2 == 0)
		X -= XSTEP / 2.f;
	else {
		if (buf > 0)
			current = 0;
		else
			current = row;
		m_Slots.emplace_back(X, Y, current);
		m_Slots.emplace_back(X, SIZE - Y, current);
		X -= XSTEP;
	}
	int bound = row / 2;
	for (int j = 0; j < bound; j++) {
		if (row >= 10) {
			if (j >= buf)
				current = row;
			else
				current = 0;
		}
		m_Slots.emplace_back(X, Y, current);
		m_Slots.emplace_back(X, SIZE - Y, current);
		m_Slots.emplace_back(SIZE - X, Y, current);
		m_Slots.emplace_back(SIZE - X, SIZE - Y, current);
		X -= XSTEP;
	}
}

void ChineseCheckers::config() {
	m_Outline.setPosition(HALF, HALF);
	m_Outline.setRadius(HALF - 5);
	m_Outline.setPointCount(m_Outline.getPointCount() * 2);
	m_Outline.setOrigin(m_Outline.getRadius(), m_Outline.getRadius());

	m_Outline.setOutlineColor(OUTLINE);
	m_Outline.setFillColor(sf::Color::Transparent);
	m_Outline.setOutlineThickness(THICK);
}

