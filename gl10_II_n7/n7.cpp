#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Car {
    string brand;
    string number;
    string ownerLastName;
    int year;
    int mileage;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Car cars[100];
    ifstream in("input.txt");

    int numCars = 0;
    while (in >> cars[numCars].brand >> cars[numCars].number >> cars[numCars].ownerLastName >> cars[numCars].year >> cars[numCars].mileage) {
        numCars++;
    }
    in.close();

    int filterYear;
    cout << "������� ���, ������������ �������� ����� ���������� ����������: ";
    cin >> filterYear;

    ofstream out("output.txt");
    for (int i = 0; i < numCars; ++i) {
        if (cars[i].year < filterYear) {
            out << cars[i].brand << " " << cars[i].number << " " << cars[i].ownerLastName << " " << cars[i].year << " " << cars[i].mileage << endl;
        }
    }
    out.close();

    cout << "������ ������� �������� � ����";
    return 0;
}

//// ������� ��� ������ ������ �� ����������� �� �����
//void readCarDataFromFile(const string& filename, Car cars[], int& numCars) {
//    ifstream file(filename);
//
//    numCars = 0;
//    while (file >> cars[numCars].brand >> cars[numCars].number >> cars[numCars].ownerLastName >> cars[numCars].year >> cars[numCars].mileage) {
//        numCars++;
//    }
//    file.close();
//}
//
//// ������� ��� ������ ������ �� ����������� � ����
//void writeCarDataToFile(const Car cars[], int numCars, int year, const string& filename) {
//    ofstream file(filename);
//
//    for (int i = 0; i < numCars; ++i) {
//        if (cars[i].year < year) {
//            file << cars[i].brand << " " << cars[i].number << " " << cars[i].ownerLastName << " " << cars[i].year << " " << cars[i].mileage << endl;
//        }
//    }
//    file.close();
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    Car cars[100];
//    int numCars;
//    int filterYear;
//    cout << "������� ���, ������������ �������� ����� ���������� ����������: ";
//    cin >> filterYear;
//
//    string inputFilename = "input.txt";
//    string outputFilename = "output.txt";
//
//    readCarDataFromFile(inputFilename, cars, numCars);
//
//    writeCarDataToFile(cars, numCars, filterYear, outputFilename);
//
//    cout << "������ ������� �������� � ����: " << outputFilename << endl;
//
//    return 0;
//}