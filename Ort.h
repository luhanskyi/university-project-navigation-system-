#pragma once
#include <string>
#include "Position.h"

class Ort
{
public:
	Ort(std::string name, Position p);
	Ort();

	std::string getName() const;
	double getX() const;
	double getY() const;

	bool operator < (const Ort& ort);

private:
	std::string name;
	Position p;
	//void setName();
};

