#include "../inc/find_road.h"
#include <fstream>
#include <iostream>


find_road::find_road()
{
    value = 0;
}

find_road::~find_road()
{
}
void find_road::setSize_adj(int n) {
    this->n = n;
    adj.resize(n);
}

void find_road::read_bus_route() {
    std::ifstream inp("assets/data/bus_route.txt");
    int val, x, y;
    while (inp >> x >> y >> val) {
        adj[x].push_back({y, val});
        adj[y].push_back({x, val});
    }
    inp.close();
}
std::vector <int> find_road::find(int st, int en, int& val, std::vector <int> visited) {
    std::vector <int> res;
    std::priority_queue <std::pair <int, int>, std::vector <std::pair <int,int>>, std::greater <std::pair <int,int>>> q;
    q.push({0, st});
    
    std::vector <int> pre(n + 1, -1);
    std::vector <int> min_val(n + 1, 100000);
    std::vector <bool> kt(n + 1, false);

    for (auto x:visited)
        kt[x] = true;
    
    min_val[st] = 0;
    pre[st] = st;
    
    while(!q.empty()) {
        int u = q.top().second;
        int value = q.top().first;
        q.pop();
        if (u == en) break;
        for (auto x:adj[u]) {
            if (!kt[x.first] &&  min_val[x.first] > value + x.second) {
                pre[x.first] = u;
                min_val[x.first] = value + x.second;
                q.push({min_val[x.first], x.first});
            }
        }
    }
    val = min_val[en];
    if (min_val[en] == 100000 || pre[en] == -1) return {};
    
    int temp = en;
    while (temp != st) {
        res.push_back(temp);
        temp = pre[temp];
    }
    res.push_back(temp);
    std::reverse(res.begin(), res.end());
    return res;
}

void find_road::draw() {
    
}