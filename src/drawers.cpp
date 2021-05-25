#include "pch.hpp"
#include "checkers.hpp"

// CLEAR SCREEN, DRAW GEOMETRY, RENDER GEOMETRY
void ChineseCheckers::draw() {
	m_Window->clear(BACKGROUND);
	m_Window->draw(m_BackImg);
	m_Window->draw(m_Outline);
	for (auto& s : m_Slots)
		s.draw(m_Window, m_Rotater); 
	m_Window->display();
}

// ROTATE BOARD WHEN ARROW KEY PRESSED
void ChineseCheckers::spin(sf::Keyboard::Key code) {
	sf::Clock clock;
	int flip;
	int degrees = 0;
	if (code == sf::Keyboard::Left)
		flip = -1;
	else
		flip = 1;
	for(;;) {
		if (abs(degrees) == 60)
			break;
		// will rotate 2 degrees (left or right) every 10 seconds
		if (clock.getElapsedTime().asMilliseconds() % 10 == 0) {
			m_Rotater.rotate(flip * 2, HALF, HALF); //transform that is "applied" when drawing board
			degrees += (flip * 2);
		}
		draw();
	}
	// clamp degrees value (0->360 domain)
	degrees %= 360;
	if (degrees < 0) degrees += 360;
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
	std::sort(
		m_Slots.begin(), m_Slots.end(),
		[](const Slot& a, const Slot& b)
		{ return a.getPosition().y < b.getPosition().y; }
	);
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

// INITIALIZING GEOMETRY OBJECTS UPON CONSTRUCTION
void ChineseCheckers::config() {
	// outside circle - setting attributes
	m_Outline.setPosition(HALF, HALF);
	m_Outline.setRadius(HALF - 5);
	m_Outline.setPointCount(m_Outline.getPointCount() * 2);
	m_Outline.setOrigin(m_Outline.getRadius(), m_Outline.getRadius());

	m_Outline.setOutlineColor(OUTLINE);
	m_Outline.setFillColor(sf::Color::Transparent);
	m_Outline.setOutlineThickness(THICK);

	// loading background "wood" texture.
	m_BackTex.loadFromFile("res/img/background.jpg");
	m_BackTex.setSmooth(true);
	m_BackImg.setTexture(m_BackTex);
	m_BackImg.setColor(sf::Color(255, 255, 255, 128));
}
