#ifndef BOX
#define BOX

#include "settings.h"

class box
{
private:
    sf::RectangleShape shape;
    sf::Text text;
    std::string content;
    std::string base_content;
    bool isClicked;
public:
    box(std::string);
    ~box();
    void draw();
    std::string& getString() {
        return content;
    }
    void setTextString() {
        text.setString(content);
    }
    void setPosition(sf::Vector2f);
    void setPos_text();
    void handleInput(std::optional <sf::Event> &);
};



#endif