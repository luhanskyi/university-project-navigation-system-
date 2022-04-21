#include "Person.h"
#include "Admin.h"
#include "User.h"
using namespace std;

void Person::Dialog()
{
	string personInput;
	cout << "User or Admin: "; cin >> personInput;

	if (personInput == "user") {
		User uObj;
		uObj.Dialog();  // eigene Dialog fuer User
	}

	else if (personInput == "Admin") {
		Admin aObj;
		aObj.Dialog(); // eigene Dialog fuer Admin
	}

	else {
		Dialog();
	}
}

void Person::addNewPlace()
{
	string new_name;
	double new_x, new_y;

	cout << "Name? "; cin >> new_name;
	cout << "X Koordinate? "; cin >> new_x;
	cout << "Y Koordinate? "; cin >> new_y;

	Position p(new_x, new_y);
	Ort* o = new Ort(new_name, p);

	vec_places.push_back(o);


}

void Person::deletePlace()
{
	//cout << vec_places[0]->getX() << vec_places[0]->getY() << vec_places[0]->getName() << endl;

	string del_name;
	cout << "Name? "; cin >> del_name;

	for (int i = 0; i < vec_places.size();i++) {
		if (vec_places[i]->getName() == del_name) {
			vec_places.erase(vec_places.begin() + i);
		}
	}

	// delete
}

void Person::ImportFromFile()
{
	string path = "Places.bin";
	ifstream fin;

	try {

		//fin.open(path);
		fin.open(path.c_str(), ios::in | ios::binary);

		if (fin.is_open()) {

			cout << "Readed" << endl;
			Ort o;

			//while(fin >> o.name)
			//while(!fin.eof())
			//fin.seekg(0);
			//fin.read((char*)&o, sizeof(Ort));

			while (fin.read((char*)&o, sizeof(Ort)))
			{
				vec_places.push_back(&o);
				cout << o.getName() << endl;
			}
		}

		else {
			throw exception("Keine Datei!");
		}
	}

	catch (const ifstream::failure& ex) {
		cout << "Caught" << ex.what() << endl;
	}

	fin.close();

}

void Person::ImportFromSCV()
{
	string path = "Places.scv";
	ifstream fin;

	try {

		fin.open(path);

		if (fin.is_open()) {

			cout << "Readed" << endl;

			double x;
			double y;
			string name;
			int counter = 0;

			while (fin.good())
			{
				string line;
				getline(fin, line, ',');

				cout << line << " ";

				if (counter == 0) {
					name = line;
				}

				if (counter == 1) {
					x = atof(line.c_str());
				}

				if (counter == 2) {
					y = atof(line.c_str());

					Position p(x, y);
					Ort* o = new Ort(name, p);
					//vec_places.push_back(o);

					counter = -1;
				}

				counter++;

			}

		}

		else {
			throw exception("Keine Datei!");
		}
	}

	catch (const ifstream::failure& ex) {
		cout << "Caught" << ex.what() << endl;
	}

	fin.close();

}

void Person::printVector() const
{
	unsigned int n = vec_places.size();
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (!(*vec_places[j - 1] < *vec_places[j])) {
				Ort tmp = *vec_places[j - 1];
				*vec_places[j - 1] = *vec_places[j];
				*vec_places[j] = tmp;
			}
		}
	}

	for (int i = 0; i < vec_places.size();i++) {
		cout << vec_places[i]->getName() << " " << vec_places[i]->getX() << " " << vec_places[i]->getY() << endl;
	}
}



bool Person::FindPlace(std::string name)
{
	for (int i = 0; i < vec_places.size();i++) {
		if (name == vec_places[i]->getName()) {
			cout << "Found" << endl;
			return true;
		}

		else if (i + 1 == vec_places.size()) {
			return false;
		}

		else continue;

	}
}

Person Person::operator += (const Ort& ort)
{
	Ort* o = new Ort;
	*o = ort;
	vec_places.push_back(o);

	return Person();
}


