#include "header/color_manip.hpp"
#include <cstdio>

sf::Color toRGB(float h, float s, float v) {
    double p, q, t, f;

    if (h == 360)
        h = 0.;
    else 
        h /= 60.;

    f = h - floor(h);
    q = v * (1. - s * f);
    p = v * (1. - s);
    t = v * (1. - s * (1. - f));

    float r = 0;
    float g = r;
    float b = r;

    switch (static_cast<int>(h)) {
        case 0:
            r = v; g = t; b = p; break;
        case 1:
            r = q; g = v; b = p; break;
        case 2:
            r = p; g = v; b = t; break;
        case 3:
            r = p; g = q; b = v; break;
        case 4:
            r = t; g = p; b = v; break;
        case 5:
            r = v; g = p; b = q; break;
    }
    return sf::Color(r * 255, g * 255, b * 255);
}

sf::Color toRGB(const HSV& in) {
    sf::Color out = toRGB(in.h, in.s, in.v);
    return out;
}

HSV toHSV(float r, float g, float b) {
    r /= 255.f;
	g /= 255.f;
	b /= 255.f;

	float max = std::max({r, g, b});
    float min = std::min({r, g, b});

    float chroma = max - min; // Chroma

    float h = 0.f;

	if (chroma != 0.f)
	{
		if (max == r)
			h = std::fmod(((g - b) / chroma), 6.f);
		else if (max == g)
			h = ((b - r) / chroma) + 2;
		else
			h = ((r - g) / chroma) + 4;

		h *= 60;
	}
	if (h < 0.f)
		h += 360;

	float v = max;	
    float s = 0.f;

	if (v != 0.f)
		s = chroma / v;

    return { h, s, v };
}

HSV toHSV(const sf::Color& in) {
    return toHSV(in.r, in.g, in.b);
}
