#include "Helpers.hpp"

float RADIUS         = 20;
float THICK          = RADIUS / 5;
float GAP            = RADIUS / 2;
float STEP           = RADIUS * 2 + GAP;
float BOARD_DIAMETER = RADIUS * 2 * 17 + GAP * 19;
float HEIGHT         = BOARD_DIAMETER + 2 * GAP;

void logf (const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    printf("\n");
    va_end(args);
}

void logColor(const sf::Color& color) {
    printf("[%d, %d, %d]\n", static_cast<int>(color.r), static_cast<int>(color.g), static_cast<int>(color.b));
}

// void loadTexture(sf::Texture* texture, const std::string& file) {
//     if (!texture->loadFromFile(file))
//         throw std::exception();
// }

// void loadAllTextures(sf::Texture (&textureArray)[12]) {
//     dirent* entry;
//     DIR* dp;

//     dp = opendir("img");
//     if (dp == NULL) {
//         perror("opendir: Path does not exist or could not be read.");
//         return;
//     }
//     int x = 0;
//     std::string name;
//     while ((entry = readdir(dp))) {
//         name = entry->d_name;
//         if (name.size() < 3) continue;
//         loadTexture(&textureArray[x], "img/" + name);
//         x++;
//     }
//     closedir(dp);
// }

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code) {
    return e.type == sf::Event::KeyPressed && e.key.code == code;
}

bool mousePressed(const sf::Event& e, const sf::Mouse::Button& code) {
    return (
        e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == code);
}
