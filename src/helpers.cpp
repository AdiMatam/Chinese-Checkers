#include "header/helpers.hpp"

void logf (const char* format, ...) {
    va_list args;
    va_start (args, format);
    vfprintf(stdout, format, args);
    printf("\n");
    va_end(args);
}

void logColor(const sf::Color& color) {
    printf("[%d, %d, %d]\n", static_cast<int>(color.r), static_cast<int>(color.g), static_cast<int>(color.b));
}

void loadImage(sf::Texture* texture, const std::string& file) {
    if (!texture->loadFromFile(file))
        throw std::exception();
}