#include "../inc/save_route.h"


save_route::save_route(/* args */):text(font_arial), name_route(font_arial)
{
    isClicked = false;

    shape.setSize({60, 30});
    shape.setPosition({905, 10});
    shape.setFillColor(green);

    text.setCharacterSize(17);
    text.setFillColor(sf::Color::Black);
    text.setString("SAVE");
    text.setPosition({912, 15});

    name_route.setCharacterSize(17);
    name_route.setFillColor(sf::Color::Black);
    name_route.setPosition({760, 15});
    name = "";

    shape_inp.setSize({150, 29});
    shape_inp.setOutlineThickness(0.7);
    shape_inp.setOutlineColor(sf::Color::Black);
    shape_inp.setFillColor(sf::Color::White);
    shape_inp.setPosition({750, 10});
}

save_route::~save_route()
{
}

void save_route::draw() {
    window.draw(shape);
    window.draw(text);
    if (isClicked) {
        window.draw(shape_inp);
        window.draw(name_route);
    }
}

void save_route::handleInput(std::optional <sf::Event> &event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
    if (event->is<sf::Event::MouseButtonPressed>()) {
        if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left){
            if (shape.getGlobalBounds().contains(mousePosF))
                isClicked = true, shape.setFillColor(sf::Color::Green);
            else 
                isClicked = false, shape.setFillColor(green);
        }
    }
    if (isClicked) {
        if (event->is<sf::Event::KeyPressed>()){
            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Backspace) {
                if (!name.empty())
                    name.pop_back();
            } else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space){
                name += " ";
            } else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Enter){
                isClicked = false;
            }
            
        }
        if (event->is<sf::Event::TextEntered>()) {
            char temp = event->getIf<sf::Event::TextEntered>()->unicode;
            if (temp >= '0' && temp < 'z')
                name += temp;
        }
        if (!name.empty()) {
            name_route.setString(name);
        }
        else {
            name_route.setString("name route");
        }
    }
}