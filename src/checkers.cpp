#include "pch.hpp"
#include "checkers.hpp"

ChineseCheckers::ChineseCheckers(sf::RenderWindow* window, int playerCount) 
	: m_Window(window), m_PlayerCount(playerCount), m_CurrentPlayer(0), m_Selected(nullptr)
{
	std::cout << "Starting Game" << std::endl;
	initiate();
	createBoard();
}

ChineseCheckers::~ChineseCheckers() {
	std::cout << "Ending Game" << std::endl;
}

void ChineseCheckers::nextTurn() {
	if (++m_CurrentPlayer >= m_PlayerCount)
		m_CurrentPlayer = 0;
}

void ChineseCheckers::draw() {
	m_Window->clear(BACKGROUND);
	m_Window->draw(m_Outline);
	m_Window->display();
}

void ChineseCheckers::createBoard() {
	m_Slots.reserve(121);
	
	std::sort(m_Slots.begin(), m_Slots.end(), [](const Slot& a, const Slot& b) { return a.getPosition().y < b.getPosition().y; });
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

void ChineseCheckers::initiate() {
	m_Outline.setPosition(HALF, HALF);
	m_Outline.setRadius(HALF - 5);
	m_Outline.setPointCount(m_Outline.getPointCount() * 2);
	m_Outline.setOrigin(m_Outline.getRadius(), m_Outline.getRadius());

	m_Outline.setOutlineColor(OUTLINE);
	m_Outline.setFillColor(sf::Color::Transparent);
	m_Outline.setOutlineThickness(THICK);
}
