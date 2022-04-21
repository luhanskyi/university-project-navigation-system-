#include "Ort.h"

using namespace std;

Ort::Ort(string name, Position p) :
	name(name), p(p)
{
}

Ort::Ort()
{
	Position new_p;
	this->name = "0";
	this->p = new_p;
}

std::string Ort::getName() const
{
	return name;
}

double Ort::getX() const
{

	return p.getX();
}

double Ort::getY() const
{
	return p.getY();
}

bool Ort::operator < (const Ort& ort)
{
	return this->getName() < ort.getName();
}


