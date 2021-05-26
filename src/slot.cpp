#include "pch.hpp"
#include "slot.hpp"

void Move::reset() {
    start = nullptr; end = nullptr;
}

// STATIC REFERENCE TO COLOR ARRAY
sf::Color* Slot::s_PlayerColors;

Slot::Slot(float x, float y, int row) {
    config();
    setPosition(x, y);
    m_Overlay.setPosition(x, y);
    determineColor(x, y, row);
}

// DETERMINES IF (X, Y) WITHIN CIRCLE
bool Slot::clicked(float mouseX, float mouseY) const {
    sf::Vector2f pos = getPosition();
    bool x = (pos.x - RADIUS <= mouseX) and (mouseX <= pos.x + RADIUS);
    return x and (pos.y - RADIUS <= mouseY) and (mouseY <= pos.y + RADIUS);
}

void Slot::draw(sf::RenderWindow* win, const sf::RenderStates& rnd) const {
    win->draw(*this, rnd);
    win->draw(m_Overlay, rnd);
}

const sf::Color& Slot::getGoalColor() {
    return *m_GoalColor;
}

// DRAW DOT ON SLOT WHEN CLICKED (TO SHOW THAT A PIECE HAS BEEN SELECTED)
void Slot::pick() {
    sf::Color flipped = sf::Color(255, 255, 255) - getFillColor();
    flipped.a = 255;
    m_Overlay.setFillColor(flipped);
}

// DE-SELECTION OF SLOT
void Slot::unpick() {
    m_Overlay.setFillColor(sf::Color::Transparent);
}

// DETERMINES IF SLOT "BELONGS" TO CURRENT_PLAYER, BASED ON COLOR
// CHECK METHODS IN HELPERS.CPP
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

// IDENTIFIES WHAT COLOR A SLOT SHOULD BE UPON CONSTRUCTION, BASED ON POSITION
void Slot::determineColor(int x, int y, int row) {
    const sf::Color* c;
    if (row == 9 or row == 0) {
        c = &sf::Color::Transparent;
        m_GoalColor = &sf::Color::Transparent;
    }

    // ASSIGNS COLOR_PTR TO ADDRESSES OF COLORS IN ARRAY (LOCATED IN HELPERS.CPP)
    // INDICIES CHOSEN SUCH THAT COLORS ACROSS FROM EACH OTHER ARE AT "OPPOSITE INDICES"
    else {
        int index;
        if (row <= 4) {
            if (y < HALF) index = 5;
            else          index = 0;
        }
        else {
            if (x < HALF) {
                if (y < HALF) index = 3;
                else          index = 1;
            }
            else {
                if (y < HALF) index = 4;
                else          index = 2;
            }
        }
        // DETERMINE INDEX OF CHOSEN COLOR AND ASSIGN "GOAL" TO THE "OPPOSITE" OF IT.
        c = &COLORS[index];
        m_GoalColor = &COLORS[5 - index];
    }
    setFillColor(*c);
    m_Overlay.setFillColor(*c);
}

