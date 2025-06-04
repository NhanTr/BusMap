#include "../inc/settings.h"

sf::ContextSettings settings;
sf::RenderWindow window;
sf::Color green = sf::Color (0, 255, 127);
sf::Color grey = sf::Color (193, 205, 205);
sf::Color spring_green = sf::Color (0, 139, 0);

sf::Vector2f mouseST;
sf::Vector2f dis_move;
bool isRelease;

void initSettings() {
    isRelease = false;
    mouseST = {0, 0};
    dis_move = {0, 0};
    settings.antiAliasingLevel = 8;
    window.create(sf::VideoMode({1000, 600}), "App", sf::Style::Default, sf::State::Windowed, settings);
}

int to_int(std::string s) {
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
        temp = temp * 10 + int(s[i] - '0');
    return temp;
}