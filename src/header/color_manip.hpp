#ifndef COLOR_MANIP_H
#define COLOR_MANIP_H

#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <algorithm>

struct HSV {
    float h, s, v;
};

sf::Color toRGB(float h, float s, float v);
sf::Color toRGB(const HSV& in);
HSV toHSV(float r, float g, float b);
HSV toHSV(const sf::Color& in);

#endif