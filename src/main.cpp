
#include "../inc/map.h"

extern void initSettings();

int main() {
    initSettings();
    map busmap;

    while (window.isOpen()) {
        std::optional <sf::Event> event;
        while (( event = window.pollEvent()))
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
            busmap.handleInput(event);
        }
 
        // Clear screen
        window.clear(sf::Color::White);
        
        busmap.draw();
        // Update the window
        window.display();
    }

}