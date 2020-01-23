#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if(!font.loadFromFile("font/arial.ttf"))
	{ 
		std::cout << "NO \n";
	}
	text.setFont(font);
	text.setString("Mouse position ");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Blue);


}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::J) && (input->isKeyDown(sf::Keyboard::K)) && (input->isKeyDown(sf::Keyboard::L)))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "J,K,W were pressed together\n";
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();

	}
	
}

// Update game objects
void Level::update()
{
	std::cout << input->getMouseX();


	std::string output = "X :" + std::to_string(input->getMouseX());
	std::string outputy = " Y :" + std::to_string(input->getMouseY());
	text.setString(output+outputy);

	
	//output + std::to_string
}

// Render level
void Level::render()
{
	beginDraw();
		
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

