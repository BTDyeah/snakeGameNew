#ifndef FRUIT_H
#define FRUIT_H
#include <SFML/Graphics.hpp>
#include <random>

class Fruit {
private:
    sf::Vector2f position;
    sf::RectangleShape fruitShape;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> cod;
public:
    Fruit(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveWhenEaten();
    //void update();  
};
#endif