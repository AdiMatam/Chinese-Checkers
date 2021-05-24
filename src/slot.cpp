#include "pch.hpp"
#include "slot.hpp"

sf::Color* Slot::s_PlayerColors;

Slot::Slot(float x, float y, int row) {
    config();
    setPosition(x, y);
    m_Overlay.setPosition(x, y);
    determineColor(x, y, row);
}

bool Slot::clicked(float mouseX, float mouseY) const {
    sf::Vector2f pos = getPosition();
    bool x = (pos.x - RADIUS <= mouseX) and (mouseX <= pos.x + RADIUS);
    return x and (pos.y - RADIUS <= mouseY) and (mouseY <= pos.y + RADIUS);
}

void Slot::draw(sf::RenderWindow* win, const sf::RenderStates& rnd) const {
    win->draw(*this, rnd);
    win->draw(m_Overlay, rnd);
}

sf::Color& Slot::getGoalColor() {
    return m_GoalColor;
}

void Slot::pick() {
    sf::Color flipped = sf::Color(255, 255, 255) - getFillColor();
    flipped.a = 255;
    m_Overlay.setFillColor(flipped);
}

void Slot::unpick() {
    m_Overlay.setFillColor(sf::Color::Transparent);
}

bool Slot::isMine(int currentPlayer, int totalPlayers) {
    int len = 6 / totalPlayers;
    getMyColors(currentPlayer, totalPlayers, s_PlayerColors, len);
    return arrContains(getFillColor(), s_PlayerColors, len);
}

bool Slot::isEmpty() {
    return getFillColor() == sf::Color::Transparent;
}

void Slot::config() {
    setRadius(RADIUS);
    setOrigin(getRadius(), getRadius());
    setOutlineColor(OUTLINE);
    setOutlineThickness(THICK);

    m_Overlay.setRadius(RADIUS / 3);
    m_Overlay.setOrigin(m_Overlay.getRadius(), m_Overlay.getRadius());
}

void Slot::determineColor(int x, int y, int row) {
    const sf::Color* c;
    if (row == 9 or row == 0) {
        c = &sf::Color::Transparent;
        m_GoalColor = sf::Color::Transparent;
    }
    else {
        if (row <= 4) {
            if (y < HALF) c = &COLORS[5];
            else          c = &COLORS[0];
        }
        else {
            if (x < HALF) {
                if (y < HALF) c = &COLORS[3];
                else          c = &COLORS[1];
            }
            else {
                if (y < HALF) c = &COLORS[4];
                else          c = &COLORS[2];
            }
        }
        int index = c - &COLORS[0];
        m_GoalColor = COLORS[5 - index];
    }
    setFillColor(*c);
    m_Overlay.setFillColor(*c);
}