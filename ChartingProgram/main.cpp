#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), L"Рисователь графиков", Style::Default);

    window.setVerticalSyncEnabled(true);
    
    Font font;
    font.loadFromFile("arialmt.ttf");
    String str = "Привет, мир!";
    Text text(str,font,300);
    text.setStyle(Text::Bold);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        text.setPosition(100, 100);
        window.clear(Color::Black);
        window.draw(text);
        window.display();
    }
    return 0;
}