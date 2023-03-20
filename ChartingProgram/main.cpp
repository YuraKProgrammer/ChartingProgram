#include <SFML/Graphics.hpp>

using namespace sf;


sf::CircleShape GetShape(int x) {
    CircleShape shape(10.f, 10);
    shape.setPosition(x+500, 1080-x*x);
    shape.setFillColor(Color::Magenta);
    return shape;
}

int main()
{
    RenderWindow window(VideoMode(1920, 1080), L"Рисователь графиков", Style::Default);

    window.setVerticalSyncEnabled(true);
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.clear(Color::Black);
        for (int x = -500; x < 1920; x++) {
            window.draw(GetShape(x));
        }
        window.display();
    }
    return 0;
}