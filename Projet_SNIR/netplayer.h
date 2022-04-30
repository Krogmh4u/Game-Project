#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"

namespace dir
{
	enum dir { DOWN, LEFT, RIGHT, UP };
}

class NetPlayer : public sf::Drawable, public sf::Transformable
{
public :
	NetPlayer();

	void Update();

	void SetCurrentMapLocation(Map* map);
	void RenderShadow();
	void TakeDamage(const int amount);

	bool IsBehindTile() const;

	sf::Vector2f GetPosition() const;
	std::string GetUsername() const;
	int getUid() const;

private :
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite PSprite, PBlackSprite;
	sf::Texture PTexture, PBlackTexture;
	sf::Vector2i PAnim;
	sf::RenderWindow* ParentWindow;

	std::string Username;
	Map* CurrentMapLocation;

	sf::Clock TimeSinceLastMove;

	float CurrentSpeed, Acceleration, MaxSpeed;
	bool IsMoving, PIsBehindTile;

	sf::Clock Time;
	float FpsCount,
		  SwitchFps,
	      FpsSpeed;

	int Health, DamageReceived, UID;
};