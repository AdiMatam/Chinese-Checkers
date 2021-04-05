#include "slot.hpp"

Slot::Slot(float x, float y, const sf::Color& c) {
    setPosition(sf::Vector2f(x, y));
    setFillColor(c);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(THICK);
    setRadius(RADIUS);
    setOrigin(getRadius(), getRadius());

    mOverlay.setFillColor(c);
    mOverlay.setPosition(sf::Vector2f(x, y));
    mOverlay.setRadius(RADIUS / 3);
    mOverlay.setOrigin(mOverlay.getRadius(), mOverlay.getRadius());
}


bool Slot::clicked(float mouseX, float mouseY) const {
    const sf::Vector2f* pos = &getPosition();
    bool x = (pos->x - RADIUS <= mouseX) && (mouseX <= pos->x + RADIUS);
    return x && (pos->y - RADIUS <= mouseY) && (mouseY <= pos->y + RADIUS);
}

void Slot::print() const {
    logVector(getPosition());
    logColor(getFillColor());
    printf("\n");
}

void Slot::pick() {
    mOverlay.setFillColor(sf::Color::Black);
}
void Slot::resetFill() {
    mOverlay.setFillColor(getFillColor());
}
