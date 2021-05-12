#include "pch.hpp"
#include "slot.hpp"

Slot::Slot(float x, float y, int row) {
    
}

bool Slot::clicked(float mouseX, float mouseY) const {
    sf::Vector2f pos = getPosition();
    bool x = (pos.x - RADIUS <= mouseX) && (mouseX <= pos.x + RADIUS);
    return x && (pos.y - RADIUS <= mouseY) && (mouseY <= pos.y + RADIUS);
}

void Slot::config() {
}
