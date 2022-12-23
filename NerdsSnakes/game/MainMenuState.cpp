

#include "game/MainMenuState.h"

#include <TGUI/TGUI.hpp>

using nerds::MainMenuState;

MainMenuState::MainMenuState(sf::RenderWindow& window)
{
    _gui.setTarget(window);
    tgui::Panel::Ptr panel = tgui::Panel::create({"50%", "50%"});
    panel->setOrigin(0.5f, 0.5f);
    panel->setPosition("50%", "50%");
    const tgui::Button::Ptr button = tgui::Button::create("Play Game");
    button->setOrigin(0.5f, 0.5f);
    button->setPosition("50%", "50%");

    panel->add(button);
    _gui.add(panel);
}

void MainMenuState::render(sf::RenderWindow& window) { _gui.draw(); }

void MainMenuState::handle_events(const sf::Event& event,
                                  sf::RenderWindow& window)
{
    _gui.handleEvent(event);
    if (event.type == sf::Event::KeyPressed)
    {
        // fullscreen _window for demonestration
        if (event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
    }
}

void MainMenuState::update() {}
