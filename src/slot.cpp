#include "Slot.hpp"

Slot::Slot(float x, float y, const sf::Color& c) {
    setPosition(sf::Vector2f(x, y));
    setFillColor(c);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(THICK);
    setRadius(RADIUS);
    setOrigin(getRadius(), getRadius());
}

// void Slot::addNeighbor(Slot& slot) {
//     mNeighbors.push_back(&slot);
// }

bool Slot::clicked(float mouseX, float mouseY) {
    const sf::Vector2f* pos = &getPosition();
    bool x = (pos->x - RADIUS <= mouseX) && (mouseX <= pos->x + RADIUS);
    return x && (pos->y - RADIUS <= mouseY) && (mouseY <= pos->y + RADIUS);
}

void Slot::print() {
    logVector(getPosition());
    logColor(getFillColor());
    log("\n");
}
