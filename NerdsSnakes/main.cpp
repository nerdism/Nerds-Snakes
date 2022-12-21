
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <vector>

int main()
{
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    const uint32_t screen_width = 1280;
    const uint32_t screen_height = 768;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height),
                            "Hello Window");

    tgui::GuiSFML gui{window};

    tgui::Button::Ptr button = tgui::Button::create("Click me");

    button->setPosition("50%", "50%");
    button->setOrigin(0.5f, 0.5f);
    button->setSize("10%", "10%");

    gui.add(button);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

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
        gui.draw();
        window.display();
    }
    return 0;
}
