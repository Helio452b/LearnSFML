/*-----------------------------------------------
			written by helio, 2019
		Chapter02 Loading and Using Textures
		when you click on the window by left mouse you can create the wall
-----------------------------------------------*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

void WindowPollEvent(RenderWindow& window, Event& event);

int main()
{
	RenderWindow window(VideoMode(1000, 500), "Getting Started");

	window.setFramerateLimit(60);	// Set Target FPS

	Event event;

	// wall 
	vector<RectangleShape> walls;

	// gird
	int gridLen = 50;

	sf::Texture textureWall;
	if (!textureWall.loadFromFile("F:\\GameAsset\\King and pig\\Sprites\\14-TileSets\\Wall01.png"))
		return -1;	

	//
	Clock clock;

	// Init TextureKingPig
	sf::Texture textureKingPig;
	if (!textureKingPig.loadFromFile("F:\\GameAsset\\King and pig\\Sprites\\02-King Pig\\Attack (38x28).png"))
		return -1;

	// Init kingPig
	sf::Vector2i kingPigSize(38, 28);
	sf::Sprite kingPig(textureKingPig);
	kingPig.setScale(Vector2f(2.0f, 2.0f));
	kingPig.setPosition(Vector2f(400, 300));
	kingPig.setOrigin(kingPig.getLocalBounds().width * 0.5f, kingPig.getLocalBounds().height * 0.5f);

	kingPig.setTextureRect(sf::IntRect(0, 0, kingPigSize.x, kingPigSize.y));

	int framesNum = 5;
	float framesDuration = 1;

	Time deltaTime, elapsedTime;

	// game loop
	while (window.isOpen())
	{
		// window scene
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Button::Left)
				{
					// create a new recShape
					int xx = event.mouseButton.x;
					int yy = event.mouseButton.y;
					xx = xx - xx % gridLen;
					yy = yy - yy % gridLen;

					RectangleShape newRec(Vector2f(gridLen, gridLen));
					newRec.setPosition(Vector2f(xx, yy));
					newRec.setTexture(&textureWall);
					
					walls.push_back(newRec);
					cout << event.mouseButton.x << event.mouseButton.y << endl;
				}
			}
		}

		// Update scene

		deltaTime = clock.restart();		

		// Accumuoate time
		elapsedTime += deltaTime;
		float timeAsSecond = elapsedTime.asSeconds();

		int animFram = static_cast<int>((timeAsSecond / framesDuration) * framesNum) % framesNum;
		kingPig.setTextureRect(IntRect(animFram * kingPigSize.x, 0, kingPigSize.x, kingPigSize.y));

		// Render cycle
		window.clear(Color::Black);		
		
		// draw wall
		for (RectangleShape i : walls)
		{			
			window.draw(i);
		}
		window.draw(kingPig);
		// Render object
		window.display();
	}
	return 0;
}

void WindowPollEvent(RenderWindow& window, Event& event)
{
	
}