#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;


sf::CircleShape GetShape(int x) {
    CircleShape shape(10.f, 10);
    shape.setPosition(x+500, 1080-x*x);
    shape.setFillColor(Color::Magenta);
    return shape;
}
int coordinate_y(int t, int a, int v, int d)
{
    return 1070 - round(t * t * a / 2 + t * v) * d;
}
int main()
{
    int t;
    int a;
    int v1;
    int v2;
    cout << "¬ведите врем€ движени€" << endl;
    cin >> t;
    cout << "¬ведите ускорение" << endl;
    cin >> a;
    cout << "¬ведите начальную скорость" << endl;
    cin >> v1;
    int x1;
    int y1;
    int x2;
    int y2;
    int division_t = round(1070 / t);
    int division_s = round(1070 / (t * t * a / 2 + t * (v1 + a * t)));
    sf::RenderWindow window(VideoMode(1080, 1080), L"–исователь графиков", Style::Default);

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
        sf::Vertex line[] =
        {
          sf::Vertex(sf::Vector2f(10, 1070)),
          sf::Vertex(sf::Vector2f(10, 0))
        };
        window.draw(line, 2, sf::Lines);

        sf::Vertex line2[] =
        {
          sf::Vertex(sf::Vector2f(10, 1070)),
          sf::Vertex(sf::Vector2f(1080, 1070))
        };
        window.draw(line2, 2, sf::Lines);
        for (int x2 = division_t; x2 < 1080; x2 += division_t) {
            x1 = round(x2 - division_t);
            v2 = round(v1 + a);
            y1 = coordinate_y(x1, a, v1, division_s);
            y2 = coordinate_y(x2, a, v2, division_s);
            sf::Vertex line[] =
            {
              sf::Vertex(sf::Vector2f(x1 + 10, y1)),
              sf::Vertex(sf::Vector2f(x2 + 10, y2))
            };
            v1 = v2;
            window.draw(line, 2, sf::Lines);

        }
        window.display();
    }
    return 0;
}