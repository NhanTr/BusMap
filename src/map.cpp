#include "../inc/map.h"
#include <fstream>
#include <iostream>

// save node in vector
void read_node(std::vector <node> &adj) {
    std::ifstream inp("assets/data/des_station.txt");
    int des, x, y;
    while (inp >> des >> x >> y) {
        node temp(des);
        temp.setPosition(x, y);
        adj.push_back(temp);
    }
    inp.close();
}
//save egde in vector
void read_edge(std::vector <edge> &adj, std::vector <node> &point) {
    std::ifstream inp("assets/data/bus_route.txt");
    int val, x, y;
    while (inp >> x >> y >> val) {
        edge temp(x - 1, y - 1, val);
        temp.setPosition(point);
        adj.push_back(temp);
    }
    inp.close();
}
//save road my map
void read_mymap(std::vector <history> &adj) {
    std::ifstream inp("assets/data/myroute.txt");
    std::string s;
    int cnt = 0;
    while (std::getline(inp, s)) {
        std::string a[3];
        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                current++;
                continue;
            }
            a[current] += s[i];
        }
        std::cout << a[0] << " " << a[1] << " " << a[2] << '\n';
        history temp(a[0]);
        temp.setPosition(sf::Vector2f(10, cnt * 25 + 50));
        temp.setUV(to_int(a[1]), to_int(a[2]));
        adj.push_back(temp);

        cnt++;
    }
    inp.close();
}

map::map(/* args */): st("START"), en("FINISH")
{   
    read_node(station);
    read_edge(route, station);
    read_mymap(history_map.getAdj());
    st.setPosition({415, 550});
    en.setPosition({505, 550});
    fr.setSize_adj(station.size() + 1);
    fr.read_bus_route();
}

map::~map()
{
}

void map::draw() {
    if (isRelease)
        moveMap();
    for (int i = 0; i < route.size(); i++) {
        route[i].setPosition(station);
        route[i].draw();
    }
    
    if (!st.getString().empty() && !en.getString().empty() && isTrue()) {
        for (auto x:fr.getAns())
            station[x - 1].setColor(grey);
            
        fr.getAns().clear();

        fr.getAns() = fr.find(to_int(st.getString()), to_int(en.getString()), fr.getValue(), {});

        std::vector<int> ans = fr.getAns();

        for (int i = 1; i < ans.size(); i++) {
            edge temp(ans[i - 1] - 1, ans[i] - 1);
            temp.setPosition(station);
            temp.setColor(green);
            temp.draw();
        }

        for (auto x:ans)
            station[x - 1].setColor(green);


        // draw text total time go 
        sf::Text t(font_arial);
        t.setCharacterSize(15);
        t.setPosition({800, 570});
        t.setFillColor(sf::Color::Red);
        t.setString("Total time " + std::to_string(fr.getValue()));
        window.draw(t);
    }
    else {
        for (auto x:fr.getAns())
            station[x - 1].setColor(grey);
        fr.getAns().clear();
    }
    for (int i = 0; i < station.size(); i++)
        station[i].draw();
    history_map.draw();
    st.draw();
    en.draw();
    sv.draw();
    if (history_map.getIsClicked_icon())
        for (auto x:history_map.getAdj())
            x.draw();
}

bool map::isTrue() {
    int u = to_int(st.getString());
    int v = to_int(en.getString());
    if (u <= 0 || u > station.size() || v <= 0 || v > station.size())
        return false;
    return true;
}

void map::handleInput(std::optional <sf::Event> &event) {
    
    push_newRoute();
    sv.handleInput(event);
    handledrag(event);
    history_map.handleInput(event);
    handleDelete(event);
    st.handleInput(event);
    en.handleInput(event);
}

void map::handledrag(std::optional <sf::Event> &event) {
    if (event->is <sf::Event::MouseButtonPressed>()) {
        if (event->getIf <sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            mouseST = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            isRelease = true;
        }
    }
    if (isRelease) {
        sf::Vector2f mouseTemp = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        dis_move = {mouseTemp.x - mouseST.x, mouseTemp.y - mouseST.y};
        
        mouseST = mouseTemp;
    }
    if (event->is <sf::Event::MouseButtonReleased>()) {
        if (event->getIf <sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Left) {
            sf::Vector2f mouseTemp = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            dis_move = {mouseTemp.x - mouseST.x, mouseTemp.y - mouseST.y};
            isRelease = false;
        }
    }
}

void map::moveMap() {
    for (auto &x:station) {
        x.shape.move(dis_move);
        x.text.move(dis_move); 
    }
    dis_move = {0, 0};
}

void map::push_newRoute() {
    if (sv.getName() != "" && !sv.getIsClicked()) {
        history temp(sv.getName());
        temp.setPosition(sf::Vector2f(10, history_map.getAdj().size() * 25 + 50));
        temp.setUV(to_int(st.getString()), to_int(en.getString()));
        history_map.getAdj().push_back(temp);

        std::ofstream out("assets/data/myroute.txt", std::ios::app);
        out << sv.getName() << "#" << st.getString() << "#"<< en.getString() << '\n';
        sv.getName() = "";
        out.close();
    }
}
void map::delete_route(int pos) {
    std::vector <history> adj = history_map.getAdj();
    
    for (int i = pos; i < history_map.getAdj().size() - 1; i++)
        history_map.getAdj()[i + 1].setPosition(sf::Vector2f(10, i * 25 + 50));
    history_map.getAdj().erase(history_map.getAdj().begin() + pos);
    std::vector <std::string> lines;
    std::string line;
    int currentline = -1;
    std::ifstream inp("assets/data/myroute.txt");
    while (std::getline(inp, line)) {
        currentline++;
        if (currentline == pos) continue;
        
        lines.push_back(line);
    }
    inp.close();
    std::cout << lines.size() << '\n';
    std::ofstream out("assets/data/myroute.txt");
    for (auto x:lines)
        out << x << '\n';
    out.close();
}
void map::handleDelete(std::optional <sf::Event> &event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
    if (event->is <sf::Event::MouseMoved>()) {
        for (int i = 0; i < history_map.getAdj().size(); i++)
            if (history_map.getAdj()[i].text.getGlobalBounds().contains(mousePosF)) {
                history_map.getAdj()[i].text.setFillColor(grey);
            }
            else {
                history_map.getAdj()[i].text.setFillColor(sf::Color::White);
            }
    }
    if (event->is <sf::Event::MouseButtonPressed>()) {
        if (event->getIf <sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Right) {
            for (int i = 0; i < history_map.getAdj().size(); i++)
                if (history_map.getAdj()[i].text.getGlobalBounds().contains(mousePosF)) {
                    delete_route(i);
                    break;
                }
        }
        if (event->getIf <sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            for (int i = 0; i < history_map.getAdj().size(); i++)
                if (history_map.getAdj()[i].text.getGlobalBounds().contains(mousePosF)) {
                    st.getString() = std::to_string(history_map.getAdj()[i].u);
                    st.setTextString();
                    en.getString() = std::to_string(history_map.getAdj()[i].v);
                    en.setTextString();
                    break;
                }
        }
    }
}