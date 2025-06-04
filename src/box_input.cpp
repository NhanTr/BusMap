#include "../inc/box_input.h"

box::box(std::string st): text(font_arial)
{
    content = "";
    base_content = st;
    isClicked = false;


    shape.setSize({80, 40});
    shape.setFillColor(green);
    shape.setOutlineThickness(3);
    shape.setOutlineColor(green);

    text.setString(base_content);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
}

box::~box()
{
}

void box::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
    setPos_text();
    
}
void box::setPos_text() {
    int temp = text.getGlobalBounds().size.x/2;
    text.setPosition({shape.getPosition().x + 40 - temp, shape.getPosition().y + 7});
}

void box::draw() {
    window.draw(shape);
    window.draw(text);
}

void box::handleInput(std::optional <sf::Event> &event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
    if (event->is<sf::Event::MouseButtonPressed>()) {
        if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left){
            if (shape.getGlobalBounds().contains(mousePosF))
                isClicked = true, shape.setFillColor(sf::Color::White);
            else 
                isClicked = false, shape.setFillColor(green);
        }
    }
    if (isClicked) {
        if (event->is<sf::Event::KeyPressed>()){
            if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Backspace) {
                if (!content.empty())
                    content.pop_back();
            } else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space){
                content += " ";
            } else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Enter){
                isClicked = false, shape.setFillColor(sf::Color::Cyan);
            }
            
        }
        if (event->is<sf::Event::TextEntered>()) {
            char temp = event->getIf<sf::Event::TextEntered>()->unicode;
            if (temp >= '0' && temp <= '9')
                content += temp;
        }
        if (!content.empty()) {
            text.setString(content);
            setPos_text();
        }
        else {
            text.setString(base_content);
            setPos_text();
        }
    }
}
