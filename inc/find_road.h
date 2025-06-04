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
    int value;
public:
    find_road();
    ~find_road();
    std::vector <int>& getAns() {
        return ans;
    }
    int& getValue() {
        return value;
    }
    void setSize_adj(int);
    void read_bus_route();
    std::vector <int> find(int, int, int &, std::vector <int> );
    void draw();
};



#endif