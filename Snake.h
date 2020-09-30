#ifndef SNAKE_H
#define SNAKE_H
//#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "Fruit.h"

class Snake{
private:
    sf::Vector2f position;
    sf::RectangleShape snakeShape; //make this into deque or whatever later
    enum class Dir {UP, DOWN, LEFT, RIGHT};
    sf::Vector2f movement;
    Dir direction;
    sf::Sprite snakeSpriteBody;
    sf::Texture snakeTextureBody;
    sf::RenderWindow myWindow;
    int windowWidth = 550;
    int windowHeight = 550;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> cod;
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key);
    void render();
    Fruit fruit;
public:
    Snake(float startX, float startY);
    sf::FloatRect getPosition();
    sf::Sprite getSprite();
    void eatingGrowth();
    void death();
    void handleMovementKeys(sf::Keyboard::Key key);
    void update();
    void isColliding();
    void run();
    //void moveHead();
};
#endif