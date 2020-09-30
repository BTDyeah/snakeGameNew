#include "Fruit.h"

Fruit::Fruit (float startX, float startY) :gen(rd()), cod(1, 520)
{
    position.x = startX;
    position.y = startY;

    fruitShape.setSize(sf::Vector2f(5, 5));
    fruitShape.setFillColor(sf::Color::Red);
    fruitShape.setPosition(position);
}

sf::FloatRect Fruit::getPosition(){
    return fruitShape.getGlobalBounds();
}

sf::RectangleShape Fruit::getShape(){
    return fruitShape;
}

//if statement must go in main function in a loop and this contains only
//what to do

void Fruit::moveWhenEaten(){
    fruitShape.setPosition(cod(gen), cod(gen));    
}
