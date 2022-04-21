#include "Hash.h"
using namespace std;

Hash::Hash()
{
    table = new list<Ort>[total_elements];
}

int Hash::getHash(Ort key)
{
    return ((int)key.getX() + (int)key.getY()) % total_elements;
}

void Hash::insertElement()
{
    string new_name;
    double new_x, new_y;

    cout << "Name? "; cin >> new_name;
    cout << "X Koordinate? "; cin >> new_x;
    cout << "Y Koordinate? "; cin >> new_y;

    Position p(new_x, new_y);
    Ort key = Ort(new_name, p);

    table[getHash(key)].push_back(key);
}

void Hash::autoinsert()
{
    string new_name = "place";
    double new_x, new_y;

    srand(time(0));

    for (int i = 0; i < 30;i++) {
        new_x = (rand() % 50);
        new_y = (rand() % 50);
        new_name = "place" + to_string(i);

        Position p(new_x, new_y);
        Ort key = Ort(new_name, p);

        table[getHash(key)].push_back(key);

    }
}

void Hash::printAll() {

    for (int i = 0; i < total_elements; i++) {
        cout << "Index " << i << ": ";

        for (Ort j : table[i])
            cout << j.getName() << " X: " << j.getX() << " Y: " << j.getY() << " ";

        cout << endl;
    }
}
