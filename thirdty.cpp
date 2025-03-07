#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
    string name;
    int year;
    int price;
public:
    void operator()() {
        string n;
        int y;
        int p;
        cin >> n;
        cin >> y;
        cin >> p;
        this->name = n;
        this->year = y;
        this->price = p;
    }
    void show() {
        cout << "Name: " << name << ", Year: " << year << ", Price: " << price << endl;
    }
};

vector<Car> cars;

void showCars() {
    for_each(cars.begin(), cars.end(), [](Car& c) {
        c.show();
    });
}

void deleteCar() {
    int i;
    cout << "Enter index: ";
    cin >> i;
    cars.erase(cars.begin() + i - 1);
}

void createCar() {
    Car temp;
    temp();
    cars.push_back(temp);
}

void menu() {
    int g;

    while (true) {
        cout << "1 - add car\n2 - delete car\n3 - show cars" << endl;
        cin >> g;
        switch (g)
        {
        case 1:
            createCar();
            break;
        case 2:
            deleteCar();
            break;
        case 3:
            showCars();
            break;
        default:
            break;
        }
    }
}

int main()
{
    menu();
}