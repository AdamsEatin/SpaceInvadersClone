// SpaceInv.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics/vertexArray.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace sf;
using namespace std;

class Invader {
public:
	float invaderX = 0, invaderY = 0;
	bool alive = true;
	RectangleShape invader;
	Texture texture;


	Invader(float x, float y) {
		invaderX = invaderX + x;
		invaderY = invaderY + y;
		invader.setSize(Vector2f(25, 25));
		invader.setFillColor(Color::White);

		if (!texture.loadFromFile("invader.png"))
			return;
		const Texture *pTexture = &texture;
		invader.setTexture(pTexture);
	}

};

class Projectile {
public:
	float projX = 0, projY = 0;
	RectangleShape projectile;
	bool projFired = false;

	Projectile(float x, float y) {
		projX = projX + x;
		projY = projY + y;
		projectile.setSize(Vector2f(2, 10));
		projectile.setFillColor(Color::Green);
	}
};

int main()
{

	//create Window
	RenderWindow window(VideoMode(400, 300), "Quiz Time");


	// set timePerFrame to 1 60th of a second. 60 frames per second
	Time timePerFrame = seconds(1.0f / 60.0f);

	// set timePerFrame for invader movement
	Time timeSinceLastUpdate = Time::Zero;

	// the clock object keeps the time.
	Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		// chek if the close window button is clicked on.
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed){
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.

		if (timeSinceLastUpdate > timePerFrame)
		{
			// get keyboard input.
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{

			}
			
		}


		// clear the screen and draw all the shapes
		window.clear();
			

		window.display();

		// reset the timeSinceLastUpdate to 0 
		timeSinceLastUpdate = Time::Zero;


		}
	}
	return 0;
}
