#ifndef __PERSON_H
#define __PERSON_H

#include "Lib.h"

class person {
private:
    string name;
    int age;
    string id;
    int rentDay;
    roomType room;
public:
    // static set<string> listID;
    string getName();
    int getAge();
    string getID();
    int getRentDay();
    roomType getRoomType();
    string getRoomTypeString();
    void setName(const string&);
    void setAge(const int&);
    void setID(const string&);
    void setRentDay(const int&);
    void setRoomType(const roomType&);
    void insertData();
    void showInfo();
};

#endif // !__PERSON_H
