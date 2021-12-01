#pragma once
#include <Box2D/Box2D.h>

//IGME 209 HW2 
//Samar Karnani

//update the game's physics since the last frame 
void Update(float _deltaTime, int32 _vInt, int32 _pInt, b2World& _world);

//displays target location and snake location
void Display(b2Body& _snake, b2Vec2& _target);

//Applies force on the snake depending on what key is pressed
void ApplyForces(char _input, b2Body& _snake);

//picks a random location between -5 and 5 for both x and y positions
void MoveTarget(float& _xPos, float& _yPos);

//returns the distance between the two vectors
float32 GetDistance(b2Vec2 _snakePos, b2Vec2 _targetPos);


