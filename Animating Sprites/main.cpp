/*-----------------------------------------------
			written by helio, 2019
		Chapter03 Animating Sprites
-----------------------------------------------*/

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void WindowPollEvent(RenderWindow& window, Event& event);

int main()
{
	RenderWindow window(VideoMode(800, 600), "Getting Started");
	Event event;
	window.setFramerateLimit(60);	// Set Target FPS
	
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
		deltaTime = clock.restart();
		// window scene
		WindowPollEvent(window, event);

		// Accumuoate time
		elapsedTime += deltaTime;
		float timeAsSecond = elapsedTime.asSeconds();

		int animFram = static_cast<int>((timeAsSecond / framesDuration) * framesNum) % framesNum;
		kingPig.setTextureRect(IntRect(animFram * kingPigSize.x, 0, kingPigSize.x, kingPigSize.y));
		
		// Update scene


		// Render cycle
		window.clear(Color::Black);
		window.draw(kingPig);

		// Render object
		window.display();
	}
	return 0;
}

void WindowPollEvent(RenderWindow& window, Event& event)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		}
	}
}