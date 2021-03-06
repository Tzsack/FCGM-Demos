#include "Player.h"


Player::Player(float mass, vec pos, vec vel, float density, color4f color)
	:Entity(mass, pos, vel, density, color)
{
	this->fuel = 0.0f;
	this->setFuel(1.0f);
}

float Player::getFuel()
{
	return this->fuel;
}

void Player::setFuel(float value)
{
	this->setColor(color4f{ 1.0f - value , value, 0.2f, 1.0f });
	this->gainMass((value - this->getFuel()) * this->getMass() / PLAYER_FUEL_MASS_RATIO);
	this->fuel = value;
}

void Player::consumeFuel(float time)
{
	this->setFuel(this->getFuel() - time * FUEL_CONSUMPTION_RATE);
	if (this->getFuel() < 0)
		this->setFuel(0.0f);
}

void Player::refillFuel(float time)
{
	this->setFuel(this->getFuel() + time * FUEL_REFILL_RATE);
	if (this->getFuel() > 1)
		this->setFuel(1.0f);
}

Player::~Player()
{
}
