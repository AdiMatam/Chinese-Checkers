#ifndef HELPERS_H
#define HELPERS_H

#include "pch.hpp"

extern float SIZE  ; 
extern float HALF  ; 
extern float GAP   ;
extern float YSTEP ;
extern float XSTEP ;
extern float RADIUS;
extern float THICK ; 


void logColor(const sf::Color& color); 

template <typename T>
void logVector(const sf::Vector2<T>& vec) {
    std::cout << "[" << vec.x << ", " << vec.y << "]\n";
}

bool keyPressed(const sf::Event& e, const sf::Keyboard::Key& code);
bool mousePressed(const sf::Event& e, const sf::Mouse::Button& code);


#endif