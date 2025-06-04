#ifndef SETTING
#define SETTING

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



extern sf::RenderWindow window;
extern sf::ContextSettings settings;
const sf::Font font_arial("assets/font/arial.ttf");
extern sf::Color green;
extern sf::Color grey;
extern sf::Color spring_green;
extern sf::Vector2f mouseST;
extern sf::Vector2f dis_move;
extern bool isRelease;

void initSettings();
int to_int(std::string);
#endif