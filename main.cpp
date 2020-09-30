#include "Snake.h"
#include "Fruit.h"
//#include <sstream>
//#include <cstdlib>
#include <random>
#include <SFML/Graphics.hpp>

int main(){
    

    int score = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> cod(1, 520);
    

    Snake snake(cod(gen), cod(gen));
    

    /*sf::Text hud;
    sf::Font font;

    THIS IS FOR THE ENDING SCREEN IN CASE OF DEATH DO NOT USE FOR NOW
    
    font.loadFromFile("DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(20);
    hud.setFillColor(sf::Color::White);
    */
    snake.run();

    return 0;
}










/*if(snake.getShape().getPosition().x < 0)
            snake.collidingRight();
        if(snake.getShape().getPosition().y < 0)
            snake.collidingUp();
        if(snake.getShape().getPosition().x + snake.getShape().getLocalBounds().width > window.getSize().x)
            snake.collidingLeft();
        if(snake.getShape().getPosition().y + snake.getShape().getLocalBounds().height > window.getSize().y)
            snake.collidingDown();
        */