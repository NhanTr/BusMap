#ifndef NE
#define NE

struct node
{
    sf::CircleShape shape;
    sf::Text text;

    node(int value):text(font_arial) {
        shape.setRadius(20);
        shape.setFillColor(grey);
        text.setCharacterSize(20);
        text.setString(std::to_string(value));
        text.setFillColor(sf::Color::Black);
    }
    void setPosition(int x, int y) {
        shape.setPosition(sf::Vector2f(x, y));
        text.setPosition(sf::Vector2f(x + 18 - text.getGlobalBounds().size.x/2, y + 5));
    }

    void setColor(sf::Color color) {
        shape.setFillColor(color);
    }
    void draw() {
        window.draw(shape);
        window.draw(text);
    }
};
struct edge
{
    sf::VertexArray line;
    sf::Text text;
    int value;
    int u, v;

    edge():line(sf::PrimitiveType::Lines, 2), text(font_arial) {
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
    }

    edge(int u, int v):line(sf::PrimitiveType::Lines, 2), text(font_arial) {
        this->u = u;
        this->v = v;
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
    }

    edge(int u, int v,int value):line(sf::PrimitiveType::Lines, 2), text(font_arial) {
        this->value = value;
        this->u = u;
        this->v = v;
        text.setCharacterSize(20);
        text.setString(std::to_string(value));
        text.setFillColor(sf::Color::Black);
    }

    void setPosition(std::vector<node> &adj) {
        sf::Vector2f posST = sf::Vector2f(adj[u].shape.getPosition());
        sf::Vector2f posEN = sf::Vector2f(adj[v].shape.getPosition());
        line[0].position = sf::Vector2f(posST.x + 20, posST.y + 20);
        line[1].position = sf::Vector2f(posEN.x + 20, posEN.y + 20);
        line[0].color = grey;
        line[1].color = grey;
        text.setPosition({(posST.x + posEN.x)/2, (posST.y + posEN.y)/2 + 10});
    }

    void setColor(sf::Color color) {
        line[0].color = color;
        line[1].color = color;
    }

    void draw() {
        window.draw(line);
        window.draw(text);
    }
};


#endif