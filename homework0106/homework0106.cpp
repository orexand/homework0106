#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(string fileName) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    string name;
    int quantity;
    double price;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    file << name << endl << quantity << endl << price << endl;
    file.close();
}

void readFromFile(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    string name;
    int quantity;
    double price;
    int id = 1;
    cout << "Id\tName\tQuantity\tPrice" << endl;
    while (file >> name >> quantity >> price) {
        cout << id << ")\t" << name << "\t" << quantity << "\t\t" << price << endl;
        id++;

    }
    file.close();
}

int main() {
    int choice;

    string fileName1 = "file1.txt";

    string fileName2 = "file2.txt";

    string fileName3 = "file3.txt";

    cout << "1. Write to file 1" << endl;
    cout << "2. Write to file 2" << endl;
    cout << "3. Write to file 3" << endl;
    cout << "4. Read from file 1" << endl;
    cout << "5. Read from file 2" << endl;
    cout << "6. Read from file 3" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        writeToFile(fileName1);
        break;
    case 2:
        writeToFile(fileName2);
        break;
    case 3:
        writeToFile(fileName3);
        break;
    case 4:
        readFromFile(fileName1);
        break;
    case 5:
        readFromFile(fileName2);
        break;
    case 6:
        readFromFile(fileName3);
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    return 0;
}