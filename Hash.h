#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include "Ort.h"
class Hash
{
private:
	std::list<Ort>* table;
	int total_elements = 100;

	// calculate hash 
	int getHash(Ort key);

public:

	Hash();
	void insertElement();
	void autoinsert();
	void printAll();
};

