#include "Admin.h"
using namespace std;

void Admin::Dialog()
{
	//ImportFromSCV();
	Hash h;

	while (true) {

		char input;
		cout << endl;
		cout << "Admin Menu:" << endl;
		cout << "\t 1.Neuen Ort (mit Namen) hinzufuegen" << endl;

		if (vec_places.size() != 0) {
			cout << "\t 2.Ort Loeschen" << endl;
		}

		if (vec_places.size() != 0) {
			cout << "\t 3.Ausgabe aller Orte (sortiert)" << endl;
		}

		cout << endl;
		cout << "\t 7.Neuen Ort (mit Namen) hinzufuegen(H)" << endl;
		cout << "\t 8.Ausgabe aller Orte(H)" << endl;
		cout << "\t 9.autoinsert(H)" << endl;
		cout << "\t x.Beenden" << endl;
		//admin

		cin >> input;
		switch (input) {
		case'1': {
			newPlace();
		} break;
		case'2': {
			deletePlace();
		} break;
		case'3': {
			printVector();
		} break;
		case'7': {
			h.insertElement();
		} break;
		case'8': {
			h.printAll();
		} break;
		case'9': {
			h.autoinsert();
		} break;
		case'x': {
			exportToSCV();
			return;
		} break;

		}
	}
}

void Admin::newPlace()
{
	Person::addNewPlace();
}

void Admin::deletePlace()
{
	Person::deletePlace();
}

void Admin::exportToSCV()
{
	string filename = "Places.scv";
	ofstream fout;

	fout.open(filename, ios::out | ios::app);

	if (!fout.is_open()) {
		cout << "not opened" << endl;
	}
	else {
		cout << "opened" << endl;

		for (int i = 0; i < vec_places.size(); i++) {
			fout << vec_places[i]->getName() << "," << vec_places[i]->getX() << "," << vec_places[i]->getY() << endl;
		}
		cout << "added" << endl;
	}

	fout.close();

}



//void Admin::ExportToFile()
//{
//	string path = "Places.bin";
//	
//	ofstream fout;
//
//	fout.open(path.c_str(), ios::out | ios::binary | ios::app);
//
//	if (!fout.is_open()) {
//		cout << "not opened" << endl;
//	}
//	else {
//		cout << "opened" << endl;
//
//		for (int i = 0; i < vec_places.size(); i++) {
//			Ort tmp = vec_places[i];
//			fout.write((char*)&tmp, sizeof(tmp));
//		}
//		cout << "added" << endl;
//	}
//
//	fout.close();
//
//}
