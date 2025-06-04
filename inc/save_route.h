#ifndef SAVE
#define SAVE

#include "settings.h"

class save_route
{
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::RectangleShape shape_inp;
    sf::Text name_route;
    std::string name;
    bool isClicked;
public:
    save_route(/* args */);
    ~save_route();
    std::string& getName(){
        return name;
    }
    bool& getIsClicked() {
        return isClicked;
    }
    void draw();
    void handleInput(std::optional <sf::Event> &);
};


#endif