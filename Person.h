#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Ort.h"
#include "Hash.h"
#include "Graph.h"
class User;
class Admin;

class Person
{
public:
	virtual void Dialog();

	void addNewPlace();
	void deletePlace();

	bool FindPlace(std::string name);

	Person operator += (const Ort& ort);

protected:
	std::vector <Ort*> vec_places;
	void ImportFromFile();
	void ImportFromSCV();
	void printVector() const;

};


