#include "../inc/history.h"
#include <iostream>

void myroute::setSprite() {
    sf::FloatRect bound = icon1.getGlobalBounds();
    icon1.setScale({30/bound.size.x, 30/bound.size.y});
    bound = icon2.getGlobalBounds();
    icon2.setScale({30/bound.size.x, 30/bound.size.y});
}

myroute::myroute(/* args */):texture1("assets/images/icon1.png"), texture2("assets/images/icon2.png") , icon1(texture1), icon2(texture2) 
{
    isClicked_icon = false;

    icon1.setPosition({5, 5});
    icon2.setPosition({5, 5});
    setSprite();

    shape.setSize({200, 600});
    shape.setFillColor(spring_green);
    
}

myroute::~myroute()
{
}

void myroute::draw() {
    if (isClicked_icon)
        window.draw(shape), window.draw(icon2);
    else 
        window.draw(icon1);
}

void myroute::handleInput(std::optional <sf::Event> &event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
    if (event->is<sf::Event::MouseButtonPressed>()) {
        if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left){
            if (icon1.getGlobalBounds().contains(mousePosF) || icon2.getGlobalBounds().contains(mousePosF)) {
                isClicked_icon = !isClicked_icon;
                if (isClicked_icon) 
                    dis_move = {200, 0};
                else 
                    dis_move = {-200, 0};
            }
        }
    }
}
void myroute::addroute() {

}
void myroute::deleteroute() {

}