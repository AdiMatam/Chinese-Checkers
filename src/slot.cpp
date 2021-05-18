#include "pch.hpp"
#include "slot.hpp"

Slot::Slot(float x, float y, int row) {
    config();
    setPosition(x, y);
    determineColor(x, y, row);
}

bool Slot::clicked(float mouseX, float mouseY) const {
    sf::Vector2f pos = getPosition();
    bool x = (pos.x - RADIUS <= mouseX) and (mouseX <= pos.x + RADIUS);
    return x and (pos.y - RADIUS <= mouseY) and (mouseY <= pos.y + RADIUS);
}

void Slot::draw(sf::RenderWindow* win, sf::Transform* t) const {
    win->draw(*this, *t);
    //win->draw(m_Overlay);
}

sf::Color& Slot::getGoalColor() {
    return m_GoalColor;
}

bool Slot::isMine(int currentPlayer, int totalPlayers) {
    int len = 6 / totalPlayers;
    sf::Color* colors = (sf::Color*)alloca(sizeof(sf::Color) * len);
    getMyColors(currentPlayer, totalPlayers, colors, len);
    return arrContains(getFillColor(), colors, len);
}

bool Slot::isEmpty() {
    return getFillColor() == sf::Color::Transparent;
}

void Slot::config() {
    setRadius(RADIUS);
    setOrigin(getRadius(), getRadius());
    setOutlineColor(OUTLINE);
    setOutlineThickness(THICK);
}

void Slot::determineColor(int x, int y, int row) {
    const sf::Color* c;
    if (row == 9 or row == 0) {
        c = &sf::Color::Transparent;
        m_GoalColor = sf::Color::Transparent;
    }
    else {
        if (row <= 4) {
            if (y < HALF) c = &COLORS[0];
            else          c = &COLORS[5];
        }
        else {
            if (x < HALF) {
                if (y < HALF) c = &COLORS[1];
                else          c = &COLORS[2];
            }
            else {
                if (y < HALF) c = &COLORS[3];
                else          c = &COLORS[4];
            }
        }
        int index = c - &COLORS[0];
        m_GoalColor = COLORS[5 - index];
    }
    setFillColor(*c);
}