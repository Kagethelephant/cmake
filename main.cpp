#include <iostream>
#include <SFML/Graphics.hpp>
#include "test.hpp"


int main()
{
    //this is the main branch
    int var = add(2,3);


    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    if(window.isOpen())
    {
        std::cout << "window is something?" << std::endl;
    }
    else
    {
        std::cout << "window is nothing?" << std::endl;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}