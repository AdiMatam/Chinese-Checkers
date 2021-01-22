#include "pch.hpp"
// #include "color_manip.hpp"
#include "helpers.hpp"

using CONSTANT = const unsigned int;
CONSTANT WIDTH = 600;
CONSTANT HEIGHT = WIDTH;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML-Window", sf::Style::Default, settings);

    log("Starting up...");

    int locs[] = 
    { 150, 450,
      450, 450,
      300, 150 };
    
    sf::VertexArray triangle(sf::Triangles, 3);
    sf::Vertex* v;
    for (int i = 0; i < 6; i += 2) {
        v = &(triangle[i / 2]);
        v->position.x = locs[i]; v->position.y = locs[i+1];
        v->color = sf::Color::White;
    }

    sf::Shader shader;
    if (!shader.loadFromFile("res/shader/fragment.shader", sf::Shader::Fragment)) {
        log("Shader loading error");
    }

    sf::Glsl::Vec4 c = sf::Color::Blue;
    shader.setUniform("u_Color", c);

    int elapsed;
    sf::Clock clock;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();
        }
        window.clear();
        window.draw(triangle, &shader);
        window.display();
    }
}