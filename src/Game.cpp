#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

inline float radians(float degrees) {
    return degrees * (3.14159 / 180);
}

const float OFFSET = 30;
const float NEAR = 245.f;
const float FAR = 420.f;

class Zone : public sf::ConvexShape {
private:
    sf::Vector2f PA;
    sf::Vector2f PB;
    sf::Vector2f PC;
public:
    Zone() {
        setPointCount(3);
        setOutlineThickness(3);
        hide();
    };
    void position(int angle) {
        PA = sf::Vector2f(HALF + NEAR * cosf(radians(angle - OFFSET)), HALF + NEAR * sinf(radians(angle - OFFSET)));
        PB = sf::Vector2f(HALF + FAR * cosf(radians(angle)), HALF + FAR * sinf(radians(angle)));
        PC = sf::Vector2f(HALF + NEAR * cosf(radians(angle + OFFSET)), HALF + NEAR * sinf(radians(angle + OFFSET)));

        setPoint(0, PA);
        setPoint(1, PB);
        setPoint(2, PC);
    }
    void show() {
        setOutlineColor(sf::Color::Black);
        setFillColor(sf::Color(140, 180, 255, 120));
    }
    void hide() {
        setOutlineColor(sf::Color(0, 0, 0, 0));
        setFillColor(sf::Color(0, 0, 0, 0));
    }
    /* implmented formula described in https://www.youtube.com/watch?v=HYAgJN3x4GA */
    bool contains(int mx, int my) {
        float w1, w2;
        w1 = PA.x * (PC.y - PA.y) + (my - PA.y) * (PC.x - PA.x) - mx * (PC.y - PA.y);
        w1 /= ((PB.y - PA.y) * (PC.x - PA.x) - (PB.x - PA.x) * (PC.y - PA.y));
        w2 = my - PA.y - (w1 * (PB.y - PA.y));
        w2 /= (PC.y - PA.y);

        return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
    }
};

struct Resonance {

};

int main() {
    auto STYLE = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Chinese Checkers", STYLE);
    sf::Event event;

    Theme theme;
    Checkers game(&window, &theme);
    
    std::array<Zone, 6> zones;
    int angle = 30;
    for (int i = 0; i < zones.size(); i++) {
        zones[i].position(angle);
        angle += 60;
    }
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || keyPressed(event, sf::Keyboard::Escape))
                window.close();

            else if (mousePressed(event, sf::Mouse::Left))
                game.processClick(event.mouseButton.x, event.mouseButton.y, false);

            else if (keyPressed(event, sf::Keyboard::Enter) && game.movedAtAll())
                game.switchTurn();
        }
        game.draw();
        //for (Zone& z : zones) {
        //    window.draw(z);
        //    auto [mx, my] = sf::Mouse::getPosition(window);
        //    if (z.contains(mx, my)) {
        //        z.show();
        //        break;
        //    }
        //    else {
        //        z.hide();
        //    }
        //}
        window.display();
    }
}
