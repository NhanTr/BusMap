#ifndef MAP
#define MAP

#include "../inc/settings.h"
#include "../inc/box_input.h"
#include "../inc/find_road.h"
#include "../inc/save_route.h"
#include "../inc/history.h"
#include <vector>
#include "node_edge.h"

class map
{
private:
    std::vector <node> station;
    std::vector <edge> route; 
    box st, en;
    find_road fr;
    sf::Vector2f move;
    save_route sv;
    myroute history_map;
public:
    map(/* args */);
    ~map();
    void draw();
    bool isTrue();
    void moveMap();
    void push_newRoute();
    void delete_route(int);
    void handleInput(std::optional <sf::Event> &);
    void handledrag(std::optional <sf::Event> &);
    void handleDelete(std::optional <sf::Event> &);
};




#endif