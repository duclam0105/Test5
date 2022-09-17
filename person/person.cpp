#include "person.h"

extern set<string> listID;

//PERSON FUNCTION//
string person::getName() { return this->name; }
int person::getAge() { return this->age; }
string person::getID() { return this->id; }
int person::getRentDay() { return this->rentDay; }
roomType person::getRoomType() { return this->room; }
string person::getRoomTypeString() {
    if (room == typeA) return "A";
    else if (room == typeB) return "B";
    else if (room == typeC) return "C";
}
void person::setName(const string& name) { this->name = name; }
void person::setAge(const int& age) { this->age = age; }
void person::setID(const string& id) { this->id = id; }
void person::setRentDay(const int& days) { this->rentDay = days; }
void person::setRoomType(const roomType& type) { this->room = type; }
void person::insertData() {
    string str_name, str_id;
    cin.ignore();
    do {
        cout << "Name: ";
        getline(cin, str_name);
        chuanhoaTen(str_name);
        if (str_name == "0") break;
    } while (!checkValidName(str_name));
    setName(str_name);
    cout << "Age: "; cin >> this->age;
    do {
        cout << "ID (10 chu so): "; cin >> str_id;
        if (str_id == "0") break;
    } while ((!checkSameID(listID, str_id)) || (!checkValidID(str_id)));
    listID.insert(str_id);
    setID(str_id);
    cout << "Rent Day: "; cin >> this->rentDay;
    // int a;
    // cout << "Room Type (0-A, 1-B, 2-C): "; cin >> a;
    // setRoomType((roomType) a);
}
void person::showInfo() {
    cout << "Name: " << name << " - Age: " << age << " - ID: " << id
        << " - Rent Day: " << rentDay << " - Room Type: " << this->getRoomTypeString() << endl;
}
