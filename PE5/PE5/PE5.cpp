#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

//IGME 209 PE5
//Samar Karnani

//Shapes to be drawn
CircleShape circle(50);
RectangleShape rect(Vector2f(100, 200));
CircleShape triangle(75, 3);
CircleShape pentagon(50, 5);
CircleShape hexagon(60, 6);

int main()	
{
	RenderWindow window(VideoMode(800, 600), "My window");

	while (window.isOpen()) {
		
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		
		//set colours for shapes
		circle.setFillColor(Color(100, 0, 0));
		rect.setFillColor(Color(0, 100, 0));
		triangle.setFillColor(Color(0, 0, 100));
		pentagon.setFillColor(Color(100, 0, 100));
		hexagon.setFillColor(Color(100, 100, 0));

		//draw shapes
		window.draw(circle);
		window.draw(rect);
		window.draw(triangle);
		window.draw(pentagon);
		window.draw(hexagon);

		//position shapes
		circle.setPosition(50, 50);
		rect.setPosition(200, 50);
		triangle.setPosition(450, 50);
		pentagon.setPosition(50, 250);
		hexagon.setPosition(300, 250);

		window.display();
	}
}
