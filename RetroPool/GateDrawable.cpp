#include "GateDrawable.hpp"


void GateDrawable::GateText(std::string TEXT)
{
	text.setCharacterSize(GateShape.getSize().x / 3);
	text.setFont(Tfont);
	text.setString(TEXT);
	text.setPosition(GateShape.getPosition().x + GateShape.getSize().x / 2 - text.getLocalBounds().width/2,
		             GateShape.getPosition().y + GateShape.getSize().y / 2 - text.getLocalBounds().height);
}

void GateDrawable::Gatesize(float width, float height)
{
	GateShape.setSize(sf::Vector2f(width, height));
}

void GateDrawable::GateColor(sf::Color color)
{
	GateShape.setFillColor(sf::Color(color));
}

void GateDrawable::GatePos(sf::Vector2f Position)
{
	GateShape.setPosition(Position);
}

void GateDrawable::GatePos(float PositionX, float PositionY)
{
	GateShape.setPosition(PositionX, PositionY);
}

void GateDrawable::GateTexture(std::string texturepath,sf::IntRect Rect)
{
	Tex.loadFromFile(texturepath);
	GateShape.setTexture(&Tex);
	GateShape.setFillColor(sf::Color::White);
	GateShape.setTextureRect(Rect);
}

sf::Vector2f GateDrawable::getGateSize()
{
	return GateShape.getSize();
}






void PinDrawable::Pinsize(float width, float height)
{
	Pinshape.setSize(sf::Vector2f(width, height));
}

void PinDrawable::PinColor(sf::Color color)
{
	Pinshape.setFillColor(sf::Color(color));
}

void PinDrawable::PinPos(sf::Vector2f Position)
{
	Pinshape.setPosition(Position);
}

void PinDrawable::PinPos(float PositionX, float PositionY)
{
	Pinshape.setPosition(PositionX, PositionY);
}

sf::Vector2f PinDrawable::getPinSize()
{
	return Pinshape.getSize();
}

bool PinDrawable::isClicked(sf::Vector2f pos)
{
	sf::FloatRect click (Pinshape.getPosition(), Pinshape.getSize());
		if (click.contains(pos))
		{

			return true;
		}
		return false;
}

void GateDrawable::LoadFont(std::string Font)
{
	if (!(Tfont.loadFromFile(Font)))
	{
		std::cout << "font faild to load" << std::endl;
	}
}
