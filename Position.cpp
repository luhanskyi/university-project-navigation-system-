#include "Position.h"

Position::Position(double x, double y) :
	x(x), y(y)
{
}

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

double Position::getX() const
{
	return x;
}

double Position::getY() const
{
	return y;
}

