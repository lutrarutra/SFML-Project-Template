#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::Window App(sf::VideoMode(1280, 720), "project_name");
    int *i = new int;
    while (App.isOpen())
    {
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}