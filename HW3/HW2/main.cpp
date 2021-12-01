#include <iostream>
#include <ctime>
#include "snake.h"
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <conio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//IGME 209 HW3 
//Samar Karnani
//The unique thing i added was an obstacle in the middle of the screen

using namespace std;
using namespace sf;

void Wrapper();

int main()
{
    Wrapper();
    _CrtDumpMemoryLeaks();
    return 0;
}

void Wrapper() {
    clock_t start;
    clock_t end;

    srand(time(NULL));
    float score = 0;
    int numKeyPresses = 0;
    const int windowWidth = 800;
    const int windowHeight = 600;
    int32 velocityInteractions = 30;
    int32 positionInteractions = 30;
    float32 minDistance = 30.0f;
    Clock deltaClock;
    Time deltaTime;

    Font font;
    font.loadFromFile("arial.ttf");
    
    enum GameStates
    {
        gameMenu,
        gamePlay,
        gameOver
    };
    GameStates gameState = gameMenu;

    b2Vec2 gravity(0.0f, -20.0f);
    b2World* world = new b2World(gravity);
    float targetHits = 0;

    //World Setup
    //create the snake
    b2BodyDef snakeDef;
    snakeDef.type = b2_dynamicBody;
    snakeDef.position.Set(0.0f, 0.0f);
    b2Body* snake = world->CreateBody(&snakeDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15.0f, 15.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    snake->CreateFixture(&fixtureDef);
    RectangleShape snakeShape(Vector2f(30, 30));
    snakeShape.setFillColor(Color(0, 0, 255));
    snakeShape.setPosition(0, 0);

    //create floor
    b2BodyDef floorDef;
    floorDef.position.Set(0.0f, -windowHeight/2);
    b2Body* floor = world->CreateBody(&floorDef);
    b2PolygonShape floorBox;
    floorBox.SetAsBox(windowWidth/2, 10.0f);
    floor->CreateFixture(&floorBox, 0.0f);
    RectangleShape floorRect(Vector2f(windowWidth, 10));
    floorRect.setFillColor(Color(255, 0, 0));
    floorRect.setPosition(0, windowHeight-10);

    //create right border
    b2BodyDef rightBorderDef;
    rightBorderDef.position.Set(windowWidth/2, 0.0f);
    b2Body* rightBorderBody = world->CreateBody(&rightBorderDef);
    b2PolygonShape rightBorderBox;
    rightBorderBox.SetAsBox(10.0f, windowHeight/2);
    rightBorderBody->CreateFixture(&rightBorderBox, 0.0f);
    RectangleShape rightBorderRect(Vector2f(10, windowHeight));
    rightBorderRect.setFillColor(Color(255, 0, 0));
    rightBorderRect.setPosition(windowWidth-10, 0);

    //create left Border
    b2BodyDef leftBorderDef;
    leftBorderDef.position.Set(-windowWidth/2, 0.0f);
    b2Body* leftBorderBody = world->CreateBody(&leftBorderDef);
    b2PolygonShape leftBorderBox;
    leftBorderBox.SetAsBox(10.0f, windowHeight/2);
    leftBorderBody->CreateFixture(&leftBorderBox, 0.0f);
    RectangleShape leftBorderRect(Vector2f(10, windowHeight));
    leftBorderRect.setFillColor(Color(255, 0, 0));
    leftBorderRect.setPosition(0, 0);

    //create obstacle
    b2BodyDef obstacleDef;
    obstacleDef.position.Set(0.0f, 0.0f);
    b2Body* obstacleBody = world->CreateBody(&obstacleDef);
    b2PolygonShape obstacleBox;
    obstacleBox.SetAsBox(5.0f, windowHeight / 3);
    obstacleBody->CreateFixture(&obstacleBox, 0.0f);
    RectangleShape obstacleRect(Vector2f(5.0f, windowHeight*2/3));
    obstacleRect.setFillColor(Color(255, 0, 0));
    obstacleRect.setPosition(windowWidth/2, windowHeight/6);

    //create roof
    b2BodyDef roofDef;
    roofDef.position.Set(0.0f, windowHeight/2);
    b2Body* roof = world->CreateBody(&roofDef);
    b2PolygonShape roofBox;
    roofBox.SetAsBox(windowWidth/2, 10.0f);
    roof->CreateFixture(&roofBox, 0.0f);
    RectangleShape roofRect(Vector2f(windowWidth, 10));
    roofRect.setFillColor(Color(255, 0, 0));
    roofRect.setPosition(0, 0);

    //create target marker
    CircleShape targetShape(15);
    targetShape.setFillColor(Color(0, 255, 0));
    targetShape.setPosition(0, 0);
    //End of world setup

    //Text elements set up
    //creates the welcome text
    sf::Text welcomeText;
    welcomeText.setFont(font);
    welcomeText.setString("welcome To...");
    welcomeText.setCharacterSize(40);
    welcomeText.setFillColor(sf::Color(255, 255, 255));
    welcomeText.setPosition(windowWidth / 2 - welcomeText.getLocalBounds().width / 2, windowHeight / 10);

    //creates the Title Text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Gravity Snake");
    titleText.setCharacterSize(100);
    titleText.setFillColor(sf::Color(0, 255, 0));
    titleText.setPosition(windowWidth / 2 - titleText.getLocalBounds().width / 2, windowHeight * 2 / 10);

    //creates the instructions for controls
    sf::Text controlsText;
    controlsText.setFont(font);
    controlsText.setString("Use the WASD Keys to move the snake!");
    controlsText.setCharacterSize(30);
    controlsText.setFillColor(sf::Color(255, 255, 255));
    controlsText.setPosition(windowWidth / 2 - controlsText.getLocalBounds().width / 2, windowHeight * 4.75 / 10);

    //Tells the player how to win
    sf::Text objectiveText;
    objectiveText.setFont(font);
    objectiveText.setString("Reach 2 targets to win the game!");
    objectiveText.setCharacterSize(30);
    objectiveText.setFillColor(sf::Color(255, 255, 255));
    objectiveText.setPosition(windowWidth / 2 - objectiveText.getLocalBounds().width / 2, windowHeight * 5.5 / 10);

    //You won text
    sf::Text winText;
    winText.setFont(font);
    winText.setString("You Won!");
    winText.setCharacterSize(100);
    winText.setFillColor(sf::Color(0, 255, 0));
    winText.setPosition(windowWidth / 2 - winText.getLocalBounds().width / 2, windowHeight * 2 / 10);

    //creates the score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string((int)score));
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color(255, 255, 255));
    scoreText.setPosition(windowWidth / 2 - scoreText.getLocalBounds().width, windowHeight * 5.5 / 10);

    //creates counter text for number of targets hit
    sf::Text targetsHitText;
    targetsHitText.setFont(font);
    targetsHitText.setString("Targets Hit: " + std::to_string(targetHits));
    targetsHitText.setCharacterSize(20);
    targetsHitText.setFillColor(sf::Color(0, 0, 255));
    targetsHitText.setPosition(20,20);

    //Creates a "Press enter" text
    sf::Text pressEnterText;
    pressEnterText.setFont(font);
    pressEnterText.setString("Press 'ENTER' to continue");
    pressEnterText.setCharacterSize(30);
    pressEnterText.setFillColor(sf::Color(0, 0, 255));
    pressEnterText.setPosition(windowWidth / 2 - pressEnterText.getLocalBounds().width/2, 6.5*windowHeight/10 + pressEnterText.getLocalBounds().height);


    //create the target vector and randomize it's position
    b2Vec2 targetVector(0.0f, 0.0f);
    MoveTarget(targetVector.x, targetVector.y);
    targetShape.setPosition(Box2dToSFML(targetVector));

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Gravity Snake");

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }


        switch (gameState)
        {
        case gameMenu:
            //Draws the text
            window.draw(welcomeText);
            window.draw(titleText);
            window.draw(controlsText);
            window.draw(objectiveText);
            window.draw(pressEnterText);
            
            //Checks for user input to start the game
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                gameState = gamePlay;
                //starts the timing of the game
                start = clock();
            }
            break;

        case gamePlay:
            deltaTime = deltaClock.getElapsedTime();
            deltaClock.restart();
            Update(deltaTime.asSeconds(), velocityInteractions, positionInteractions, *world);

            //check for user input and calls the appropriate method
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                ApplyForces('a', *snake);
                numKeyPresses++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                ApplyForces('d', *snake);
                numKeyPresses++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                ApplyForces('w', *snake);
                numKeyPresses++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                ApplyForces('s', *snake);
                numKeyPresses++;
            }

            //checks to see if the target is close to the snake, if it is it moves the target
            if (GetDistance(snake->GetPosition(), targetVector) < minDistance) {
                targetHits++;
                MoveTarget(targetVector.x, targetVector.y);
                targetShape.setPosition(Box2dToSFML(targetVector));

                //Checks to see if the player has beaten the game 
                if (targetHits >= 2) {
                    gameState = gameOver;

                    //stop the timing of the game
                    end = clock();
                    
                    //calculates score
                    float timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
                    score =   (float)numKeyPresses / timeTaken;
                    scoreText.setString("Score: " + std::to_string((int)score));

                }
            }
            snakeShape.setPosition(Box2dToSFML(snake->GetPosition()));
            targetsHitText.setString("Targets Hit: " + std::to_string(targetHits));

            //draws the objects and text
            window.draw(roofRect);
            window.draw(floorRect);
            window.draw(leftBorderRect);
            window.draw(rightBorderRect);
            window.draw(obstacleRect);
            window.draw(targetShape);
            window.draw(snakeShape);
            window.draw(targetsHitText);

            break;

        case gameOver:
            //draws the text 
            window.draw(winText);
            window.draw(scoreText);
            window.draw(pressEnterText);
            
            //checks for user inpur to close the window
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                window.close();
            }
            break;

        default:
            break;
        }
    
        window.display();
    }

    //destroys all bodies and the world
    world->DestroyBody(floor);
    world->DestroyBody(roof);
    world->DestroyBody(leftBorderBody);
    world->DestroyBody(rightBorderBody);
    world->DestroyBody(snake);

    delete world;

}

