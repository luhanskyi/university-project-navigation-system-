#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"

class Admin :public Person
{

public:
	void Dialog() override;

private:
	void newPlace();
	void deletePlace();

	//void ExportToFile();
	void exportToSCV();

};
