#include "pch.hpp"
#include "color_manip.hpp"
#include "helpers.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 256;
CONSTANT HEIGHT = WIDTH;

void setVertex(sf::Vertex& v, int x, int y, int hue) {
    v.position.x = x;
    v.position.y = y;
    v.color = toRGB(hue, x / 255.f, 1.f - y / 255.f);
}

void updateVertexArray(sf::VertexArray& rects, int hue) {
    int idx;
    int y;
    for (int i = 0; i < rects.getVertexCount() / 4; i++) {
        y = i * 60;
        idx = i * 4;
        setVertex(rects[idx], 0, y, hue);
        setVertex(rects[idx + 1], 255, y, hue);
        setVertex(rects[idx + 2], 255, y + 60, hue);
        setVertex(rects[idx + 3], 0, y + 60, hue);
    }
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window", sf::Style::Default, settings);

    log("Starting up...");

    int hue = 0;
    const int rectCount = 6;
    sf::VertexArray rects(sf::Quads, rectCount * 4);

    int idx;
    int y;

    for (int i = 0; i < rectCount; i++) {
        y = i * 60;
        idx = i * 4;
        setVertex(rects[idx], 0, y, hue);
        setVertex(rects[idx + 1], 255, y, hue);
        setVertex(rects[idx + 2], 255, y + 60, hue);
        setVertex(rects[idx + 3], 0, y + 60, hue);
    }

    int elapsed;
    sf::Clock clock;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
        }
        window.clear();
        elapsed = clock.getElapsedTime().asMilliseconds();
        if (elapsed >= 10) {
            hue++;
            if (hue == 360.f) hue = 0.f;   
            clock.restart();
            updateVertexArray(rects, hue);
        }
        window.draw(rects);
        window.display();
    }
}