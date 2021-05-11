#include "pch.hpp"

float RADIUS = 18.f;
float THICK  = 3.f;
float GAP    = RADIUS;
float XSTEP  = RADIUS * 2 + GAP;
float YSTEP  = sqrtf(powf(XSTEP, 2.f) - powf(GAP / 2.f + RADIUS, 2.f));
float SIZE   = (YSTEP * 17) + (GAP * 2);
float HALF   = SIZE / 2;
