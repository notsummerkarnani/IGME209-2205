#include "snake.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>

//IGME 209 HW3 
//Samar Karnani

using namespace std;
using namespace sf;

//Updates the game physics since the last frame
void Update(float _deltaTime, int32 _vInt, int32 _pInt, b2World& _world) {
	_world.Step(_deltaTime, _vInt, _pInt);
}

//displays target location and snake location
//void Display(b2Body& _snake, b2Vec2& _target) {
//	b2Vec2 snakePosition = _snake.GetPosition();
//	printf("Target: (%.2f, %.2f) --> Snake: (%.3f, %.3f)\n", _target.x, _target.y, snakePosition.x, snakePosition.y);
//}

//Applies force on the snake depending on what key is pressed
void ApplyForces(char _input, b2Body& _snake) {
	b2Vec2* force;
	switch (_input) {
	case 'w':	//Upward force
		force = new b2Vec2(0.0f, 500000.0f);
		break;

	case 'a':	//leftward force
		force = new b2Vec2(-500000.0f, 0.0f);
		break;

	case 's':	//downwards fforce
		force = new b2Vec2(0.0f, -100000.0f);
		break;

	case 'd':	//right force
		force = new b2Vec2(500000.0f, 0.0f);
		break;

	default:	//default case, no force 
		force = new b2Vec2(0.0f, 0.0f);
		break;
	}
	_snake.ApplyForceToCenter(*force, true);

	delete force;
}

//picks a random location between -5 and 5 for both x and y positions
void MoveTarget(float& _xPos, float& _yPos) {
	float newXPos = ((rand() % 101) / 10.0f) - 5.0f;
	float newYPos = ((rand() % 101) / 10.0f) - 5.0f;

	_xPos = newXPos * 75;
	_yPos = newYPos * 55;
}

//returns the distance between the two vectors
float32 GetDistance(b2Vec2 _snakePos, b2Vec2 _targetPos) {
	return b2Distance(_snakePos, _targetPos);
}

//Returns a vector in the SFML coordinate system from a vector in the box2d coordinate system
sf::Vector2f Box2dToSFML(b2Vec2 _boxVector) {
	sf::Vector2f sfmlVector(0, 0);
	if (_boxVector.x < 0) {
		sfmlVector.x = 400 - abs(_boxVector.x) -15;
	}
	if (_boxVector.x >= 0) {
		sfmlVector.x = 400 + _boxVector.x - 15;
	}
	if (_boxVector.y < 0) {
		sfmlVector.y = 300 + abs(_boxVector.y) - 15;
	}
	if (_boxVector.y >= 0) {
		sfmlVector.y = 300 - _boxVector.y - 15;
	}
	return sfmlVector;
}