#ifndef HELPERS_H
#define HELPERS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include <cstdarg>
#include <iostream>
#include <dirent.h>

template <typename T>
void log (T object) {
    std::cout << object << std::endl;
}

void logf (const char* format, ...);

void logColor(const sf::Color& color); 

void loadTexture(sf::Texture* texture, const std::string& file);

void loadAllTextures(sf::Texture (&textureArray)[12]);

#endif