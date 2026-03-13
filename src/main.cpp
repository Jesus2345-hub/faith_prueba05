#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // SFML 3: VideoMode con llaves {}
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Mi Juego SFML 3");

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    // SFML 3: Bucle de eventos
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            // Opcional: mover con teclas
            if (auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}