#include <iostream>
#include <ctime>
#include "snake.h"
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <conio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//IGME 209 HW2 
//Samar Karnani

using namespace std;
using namespace sf;

int main()
{
    clock_t start;
    clock_t end;

    srand(time(NULL));
    float score = 0;
    int numKeyPresses = 0;
    cout << "Welcome to Gravity Snake!" << endl;
    cout << "Use the WASD keys to move the snake. Hit the target 2 times to win!" << endl;

    b2Vec2 gravity(0.0f, -0.10f);
    b2World* world = new b2World(gravity);


    //World Setup
    //create the snake
    b2BodyDef snakeDef;
    snakeDef.type = b2_dynamicBody;
    snakeDef.position.Set(0.0f, 0.0f);
    b2Body* snake = world->CreateBody(&snakeDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    snake->CreateFixture(&fixtureDef);

    //create floor
    b2BodyDef floorDef;
    floorDef.position.Set(0.0f, -8.5f);
    b2Body* floor = world->CreateBody(&floorDef);
    b2PolygonShape floorBox;
    floorBox.SetAsBox(5.0f, 2.0f);
    floor->CreateFixture(&floorBox, 0.0f);

    //create right border
    b2BodyDef rightBorderDef;
    rightBorderDef.position.Set(8.5f, 0.0f);
    b2Body* rightBorderBody = world->CreateBody(&rightBorderDef);
    b2PolygonShape rightBorderBox;
    rightBorderBox.SetAsBox(2.0f, 5.0f);
    rightBorderBody->CreateFixture(&rightBorderBox, 0.0f);

    //create left Border
    b2BodyDef leftBorderDef;
    leftBorderDef.position.Set(-8.5f, 0.0f);
    b2Body* leftBorderBody = world->CreateBody(&leftBorderDef);
    b2PolygonShape leftBorderBox;
    leftBorderBox.SetAsBox(2.0f, 5.0f);
    leftBorderBody->CreateFixture(&leftBorderBox, 0.0f);
    
    //create roof
    b2BodyDef roofDef;
    roofDef.position.Set(0.0f, 8.5f);
    b2Body* roof = world->CreateBody(&roofDef);
    b2PolygonShape roofBox;
    roofBox.SetAsBox(5.0f, 2.0f);
    roof->CreateFixture(&roofBox, 0.0f);
    //End of world setup


    //create the target vector and randomize it's position
    b2Vec2 targetVector(0.0f, 0.0f);
    MoveTarget(targetVector.x, targetVector.y);

    float targetHits = 0;

    int32 velocityInteractions = 8;
    int32 positionInteractions = 3;

    //Allows the user to read the instructions and start the game when ready
    cout << "Press \"Enter\" to start the Game." << endl;
    char input = ' ';
    while (input != 13) {
        if (_kbhit()) {
            input = _getch();
        }
    }

    //b2Vec2 snakePosition = snake->GetPosition();
    float32 minDistance = 0.8f;

    //starts the timing of the game
    start = clock();

    Clock deltaClock;
    Time deltaTime;
    //The main game loop (loops until ESC is pressed or target was hit twice)
    while (input != 27 && targetHits < 2) {
        deltaTime = deltaClock.getElapsedTime();
        deltaClock.restart();

        Update(deltaTime.asSeconds(), velocityInteractions, positionInteractions, *world);

        if (_kbhit()) {
            input = _getch();
            ApplyForces(input, *snake);
            numKeyPresses++;
        }

        //checks to see if the target is close to the snake, if it is it moves the target
        if (GetDistance(snake->GetPosition(), targetVector) < minDistance) {
            targetHits++;

            cout << "Target Hit!" << endl;
            MoveTarget(targetVector.x, targetVector.y);
        }

        //prints out information about the snake
        Display(*snake, targetVector);
    }
    //stop the timing of the game
    end = clock();

    //calcualte the score
    float timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
    score = 100 * (float)numKeyPresses / timeTaken;

    //Print out informatino about the end of the game
    if (input == 27) {
        cout << "\nGame Over! Play Again soon!" << endl;
    }
    else {
        cout << "\nYou Won! Your score was: " << score << endl;
    }

    //This makes sure the game doesnt end suddenly
    cout << "\n\nPress \"Escape\" to end the Program." << endl;
    while (input != 27) {
        if (_kbhit())input = _getch();
    }

    //destroys all bodys and the world to get rid of memory leaks
    world->DestroyBody(floor);
    world->DestroyBody(roof);
    world->DestroyBody(leftBorderBody);
    world->DestroyBody(rightBorderBody);
    world->DestroyBody(snake);

    delete world;

    _CrtDumpMemoryLeaks();
    return 0;
}

