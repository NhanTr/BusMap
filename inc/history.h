#ifndef MYROUTE
#define MYROUTE

#include "settings.h"

struct history
{
    sf::Text text;
    std::string content;
    int u, v;
    history(std::string s):text(font_arial) {
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::White);
        content = s;
        text.setString(s);
    }

    void setPosition(sf::Vector2f pos) {
        text.setPosition(pos);
    }
    void setUV(int x, int y) {
        u = x;
        v = y;
    }
    void draw() {
        window.draw(text);
    }
};


class myroute
{
private:
    std::vector<history> adj;
    sf::RectangleShape shape;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Sprite icon1;
    sf::Sprite icon2;
    bool isClicked_icon;
public:
    myroute(/* args */);
    ~myroute();
    std::vector <history>& getAdj() {
        return adj;
    }
    bool& getIsClicked_icon() {
        return isClicked_icon;
    }
    void addroute();
    void deleteroute();
    void draw();
    void handleInput(std::optional <sf::Event> &);
    void setSprite();

};




#endif