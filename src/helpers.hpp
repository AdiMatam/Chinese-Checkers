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

extern sf::Color OUTLINE;
extern sf::Color BACKGROUND;
extern sf::Color COLORS[6];

void getMyColors(int currPlayer, int totalPlayers, sf::Color* colors, int len);
bool arrContains(const sf::Color& search, sf::Color* array, int len);
bool keyPressed(sf::Event& ev, sf::Keyboard::Key code);
bool mousePressed(sf::Event& ev, sf::Mouse::Button code);

#endif