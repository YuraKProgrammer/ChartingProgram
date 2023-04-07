#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;


const int winSize = 1080; // размер окна
const int regSize = 1070; // размер области для рисования
const int regIndent = 10; // отступ области для рисования

class Point 
{
public:
    Point(int x, int y) 
    {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
private:
    int x = 0;
    int y = 0;
};

int coordinate_y(float t, float a, float v, int d)
{
    return regSize - round(t * t * a / 2 + t * v) * d;
}
int main()
{
    float travelTime = regSize; // время в пути
    float acceleration = 0.01; // ускорение
    float startingSpeed = 1; // начальная скорость
    float nextSpeed1 = startingSpeed;
    float nextSpeed2 = 0;
    //cout << "Введите время движения" << endl;
    //cin >> t;
    //cout << "Введите ускорение" << endl;
    //cin >> a;
    //cout << "Введите начальную скорость" << endl;
    //cin >> v1;
    int x1 = 1;
    int y1 = 1;
    int y2 = 1;
    int division_t = round(regSize / travelTime);
    int division_s = division_t;//(travelTime * travelTime * acceleration / 2 + travelTime * (startingSpeed + acceleration * travelTime)));
    sf::RenderWindow window(VideoMode(winSize, winSize), L"Graph Builder", Style::Default);

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
          sf::Vertex(sf::Vector2f(regIndent, regSize)),
          sf::Vertex(sf::Vector2f(regIndent, 0))
        };
        window.draw(line, 2, sf::Lines);

        sf::Vertex line2[] =
        {
          sf::Vertex(sf::Vector2f(regIndent, regSize)),
          sf::Vertex(sf::Vector2f(winSize, regSize))
        };
        window.draw(line2, 2, sf::Lines);
        for (int x2 = division_t; x2 < winSize; x2 += division_t) {
            x1 = round(x2 - division_t);
            nextSpeed2 = round(nextSpeed1 + acceleration);
            y1 = coordinate_y(x1, acceleration, startingSpeed, division_s);
            Point p1(x1 + regIndent, y1);
            y2 = coordinate_y(x2, acceleration, startingSpeed, division_s);
            Point p2(x2 + regIndent, y2);
            sf::Vertex line[] =
            {
              sf::Vertex(sf::Vector2f(p1.getX(),p1.getY())),
              sf::Vertex(sf::Vector2f(p2.getX(),p2.getY()))
            };
            nextSpeed1 = nextSpeed2;
            line->color = Color::Red;
            window.draw(line, 2, sf::Lines);
        }
        window.display();
    }
    return 0;
}