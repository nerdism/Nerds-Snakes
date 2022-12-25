

#include "game/MainMenuState.h"

#include <TGUI/TGUI.hpp>

using nerds::MainMenuState;

MainMenuState::MainMenuState(sf::RenderWindow& window)
{
    _gui.setTarget(window);
    // tgui::Panel::Ptr panel = tgui::Panel::create({"50%", "50%"});
    // panel->setOrigin(0.5f, 0.5f);
    // panel->setPosition("50%", "50%");

    tgui::VerticalLayout::Ptr menu_buttons_vlayout =
        tgui::VerticalLayout::create();
    menu_buttons_vlayout->setOrigin(0.5f, 0.5f);
    menu_buttons_vlayout->setSize("30%", "50%");
    menu_buttons_vlayout->setPosition("50%", "50%");

    const tgui::Button::Ptr play_game_button =
        tgui::Button::create("Play Game");
    const tgui::Button::Ptr settings_button = tgui::Button::create("Settings");
    const tgui::Button::Ptr exit_button = tgui::Button::create("Exit");
    exit_button->onClick([&]() { window.close(); });

    menu_buttons_vlayout->add(play_game_button);
    menu_buttons_vlayout->add(settings_button);
    menu_buttons_vlayout->add(exit_button);
    menu_buttons_vlayout->insertSpace(2, 0.5f);
    menu_buttons_vlayout->insertSpace(1, 0.5f);
    _gui.add(menu_buttons_vlayout);
}

void MainMenuState::render(sf::RenderWindow& /*window*/) { _gui.draw(); }

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
