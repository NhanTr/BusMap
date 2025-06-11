#ifndef FIND
#define FIND

#include "settings.h"
#include "node_edge.h"

class find_road
{
private:
    std::vector <std::vector <std::pair <int,int>>> adj;//save node beside and value of edge
    std::vector <edge> route;
    int n;
    std::vector <int> ans;
    std::vector <int> the_second_ans;
    int value;
public:
    find_road();
    ~find_road();
    int get_nums_station() {
        return n;
    }
    std::vector <int>& getAns() {
        return ans;
    }
    std::vector <int>& get_theSecond_road() {
        return the_second_ans;
    }
    int& getValue() {
        return value;
    }
    void setSize_adj(int);
    void read_bus_route();
    std::vector <int> find(int, int, int &, std::vector <int>);
    std::vector <int> find_the_second_road(int, int, std::vector <int>);
    void print_all_road();
    void draw();
};



#endif