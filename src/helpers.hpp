#ifndef HELPERS_H
#define HELPERS_H

#include "pch.hpp"
#include <dirent.h>

extern float HEIGHT        ; 
extern float BOARD_DIAMETER; 
extern float GAP           ;
extern float STEP          ;
extern float RADIUS        ;
extern float THICK         ; 

void logColor(const sf::Color& color); 

template <typename T>
void logVector(const sf::Vector2<T>& vec) {
    std::cout << "[" << vec.x << ", " << vec.y << "]\n";
}

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code);
bool mousePressed(const sf::Event& e, const sf::Mouse::Button& code);


#endif