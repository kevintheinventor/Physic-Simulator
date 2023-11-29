#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void getPlayerPostion(CircleShape *playerModel, Text &playerPostion)
{
	Vector2f currPosition = (*playerModel).getPosition();

	// Convert the origin position to a string for display
	string currPositionString = "( " +to_string(currPosition.x) + ", " + to_string(currPosition.y) + " )";

	// Set the text's string and position
	playerPostion.setString(currPositionString);
}

int main()
{
	//------------------------------------Initailization-----------------------------------------------------------------------------
	float screenWidth = 800;
	float screenHeight = 600;
	VideoMode vm(screenWidth, screenHeight);
	RenderWindow window(vm, "test", Style::Default);

	//Osaka font
	Font Osakafont;
	Osakafont.loadFromFile("fonts/Osaka.ttf"); //load osaka to Osakafont

	//Krungthep font
	Font Krungthepfont;
	Krungthepfont.loadFromFile("fonts/Krungthep.ttf");

	//Intro text
	Text introMessage("Physic!", Osakafont, 50); // set up intro message
	introMessage.setFillColor(Color::White); // fill in the color
	FloatRect textRect = introMessage.getLocalBounds(); //find the intro message's hit box
	introMessage.setOrigin((textRect.left + textRect.width) / 2.0f, (textRect.top + textRect.height) / 2.0f); // set the origin to the middle of the hit box
	introMessage.setPosition(screenWidth / 2, screenHeight / 2); // set text to the middle of the screen

	//Player postion Text
	Text playerPostion("", Krungthepfont, 10);
	playerPostion.setFillColor(Color::White);
	playerPostion.setPosition(0, 0);

	//Circle shape
	CircleShape player(3.0f);
	player.setOrigin(player.getRadius(), player.getRadius());
	player.setPosition(screenWidth / 4, screenHeight / 4);

	//-----------------------------------main game loop-----------------------------------------------------------------------------------
	while (window.isOpen())
	{

		// user input
		if (Keyboard::isKeyPressed(Keyboard::Escape)) // closing window
		{
			window.close();
		}
		//moving player
		if (Keyboard::isKeyPressed(Keyboard::W)) //up
		{
			if (player.getPosition().y - player.getRadius() <= 0)
			{

			}
			else
			{
				player.move(0, -.1f);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) //down
		{
			if (player.getPosition().y + player.getRadius() >= screenHeight)
			{

			}
			else
			{
				player.move(0, .1f);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) //left
		{
			if (player.getPosition().x - player.getRadius() <= 0)
			{

			}
			else
			{
				player.move(-.1f, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) //right
		{
			if (player.getPosition().x + player.getRadius() >= screenWidth)
			{

			}
			else
			{
				player.move(.1f, 0);
			}
		}

		getPlayerPostion(&player, playerPostion);

		window.clear();
		window.draw(introMessage);
		window.draw(player);
		window.draw(playerPostion);
		window.display();

	}
	return 0;
}
