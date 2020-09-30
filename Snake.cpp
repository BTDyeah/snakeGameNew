#include "Snake.h"
#include "Fruit.h"

Snake::Snake(float startX, float startY) : myWindow(sf::VideoMode(windowWidth, windowHeight), "snakeGame", sf::Style::Close | sf::Style::Titlebar), gen(rd()), cod(1, 520), movement(0.f, 0.f), fruit(cod(gen), cod(gen)) {
    position.x = startX;
    position.y = startY;

    snakeTextureBody.loadFromFile("snakeBody.png");
    snakeSpriteBody.setTexture(snakeTextureBody);


    direction = Dir::UP;
    
    snakeSpriteBody.setPosition(position);
}

sf::FloatRect Snake::getPosition(){
    return snakeShape.getGlobalBounds();
}

sf::Sprite Snake::getSprite(){
    return snakeSpriteBody;
}

void Snake::eatingGrowth(){
    //add a single entity as a new "brick" or a "tail"
}

void Snake::death(){
    //idk make that last and make some kind of a death screen "RETRY EXIT"
}

void Snake::handleMovementKeys(sf::Keyboard::Key key){
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    //    myWindow.close();
    //else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction = Dir::LEFT;
    else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction = Dir::RIGHT;
    else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction = Dir::DOWN;
    else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction = Dir::UP;
}

void Snake::update(){
    switch (direction) {
            case Dir::UP:
                movement.y -= 0.05f;
                break;

            case Dir::DOWN:
                movement.y += 0.05f;
                break;

            case Dir::LEFT:
                movement.x -= 0.05f;
                break;

            case Dir::RIGHT:
                movement.x += 0.05f;
                break;
        }  
    
    isColliding();
}

void Snake::isColliding(){
    if (snakeSpriteBody.getPosition().x < 0 ) { movement.x = myWindow.getSize().x - snakeSpriteBody.getLocalBounds().width;  }
    if (snakeSpriteBody.getPosition().y < 0 ) { movement.y = myWindow.getSize().y - snakeSpriteBody.getLocalBounds().height; }
    if (snakeSpriteBody.getPosition().x + snakeSpriteBody.getLocalBounds().width > myWindow.getSize().x )  { movement.x = snakeSpriteBody.getLocalBounds().width - myWindow.getSize().x; }
    if (snakeSpriteBody.getPosition().y + snakeSpriteBody.getLocalBounds().height > myWindow.getSize().y ) { movement.y = snakeSpriteBody.getLocalBounds().height - myWindow.getSize().y; }
    snakeSpriteBody.move(movement);
}

void Snake::processEvents(){
    sf::Event evnt;
    while(myWindow.pollEvent(evnt)){
        switch(evnt.type){
            case sf::Event::KeyPressed: handlePlayerInput(evnt.key.code); break;
            case sf::Event::Closed: myWindow.close(); break;
        }
    }
}

void Snake::handlePlayerInput(sf::Keyboard::Key key){
        if (key == sf::Keyboard::W || key == sf::Keyboard::Up) direction = Dir::UP;
        else if (key == sf::Keyboard::S || key == sf::Keyboard::Down) direction = Dir::DOWN;
        else if (key == sf::Keyboard::A || key == sf::Keyboard::Left) direction = Dir::LEFT;
        else if (key == sf::Keyboard::D || key == sf::Keyboard::Right) direction = Dir::RIGHT;
}

void Snake::render(){
        myWindow.clear();
        myWindow.draw(getSprite());   
        myWindow.draw(fruit.getShape());
        myWindow.display();
}

void Snake::run(){
    while (myWindow.isOpen()){
            processEvents();
            update();
            render();
        }
}