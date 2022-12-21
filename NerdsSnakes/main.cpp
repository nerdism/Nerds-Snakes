
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    const uint32_t screen_width = 1280;
    const uint32_t screen_height = 768;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height),
                            "Hello Window");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // window close button
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                // fullscreen window for demonestration
                if (event.key.code == sf::Keyboard::Enter)
                {
                    window.create(desktop, "Hello Window",
                                  sf::Style::Fullscreen);
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}
