/*-----------------------------------------------
			written by helio, 2019
		  Chapter01 Getting Started
-----------------------------------------------*/

#include <SFML/Graphics.hpp>

using namespace sf;

void WindowPollEvent(RenderWindow& window, Event& event, int& moving);
void InitShape(RectangleShape& Shape, Vector2f const& pos, Color const& Color);

int main()
{
	RenderWindow window(VideoMode(1200, 300), "Getting Started");
	
	window.setFramerateLimit(60);	// Set Target FPS

	Event event;

	const Vector2f playerPos(0.0f, 0.0f);
	const Vector2f enemyPos(200.0f, 0.0f);
	const Vector2f dstPos(400.0f, 0.0f);

	const Vector2f playerSize(30.0f, 30.0f);
	const Vector2f enemySize(50.0f, 100.0f);
	const Vector2f dstSize(100.0f, 100.0f);
 
	RectangleShape player(playerSize);
	RectangleShape enemy(enemySize);
	RectangleShape dst(dstSize);

	InitShape(player, playerPos, Color::Green);
	InitShape(enemy, enemyPos, Color::Yellow);
	enemy.setOrigin(enemy.getSize() * 0.5f);
	InitShape(dst, dstPos, Color::Blue);

	// move
	int moving = 0;

	// game loop
	while (window.isOpen())
	{
		// window scene
		WindowPollEvent(window, event, moving);

		// Update scene
		player.move(Vector2f(1.0f, 0.0f));
		
		if (moving != 0)
		{
			player.move(Vector2f(0.0f, -moving));
			 
		}
		
		if (player.getGlobalBounds().intersects(dst.getGlobalBounds()))
		{					 		 
			window.waitEvent(event);
			window.close();
		}
		if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
 
			player.setPosition(playerPos);

		 
		enemy.rotate(1.5f);
		// Render cycle
		window.clear(Color::Black);

		window.draw(player);
		window.draw(enemy);
		window.draw(dst);
 
		// Render object
		window.display();
	}
	return 0;
}

void WindowPollEvent(RenderWindow& window, Event& event, int& moving)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Key::Up)
				moving = 1;
			break;
		case Event::KeyReleased:
			if (event.key.code == Keyboard::Key::Down)
				moving = -1;
			break;
		}
	}
}

void InitShape(RectangleShape& recShape, Vector2f const& pos, Color const& Color)
{
	recShape.setPosition(pos);
	recShape.setFillColor(Color);
}