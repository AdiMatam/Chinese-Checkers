#ifndef HELPERS_H
#define HELPERS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include <cstdarg>
#include <iostream>

template <typename T>
void log (T object) {
    std::cout << object << std::endl;
}

void logf (const char* format, ...);

void logColor(const sf::Color& color); 

void loadImage(sf::Texture* texture, const std::string& file);

#endif