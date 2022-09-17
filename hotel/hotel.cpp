#include "hotel.h"

extern set<string> listID;

//HOTEL FUNCTION//
int hotel::getPriceA() { return this->priceA; }
int hotel::getPriceB() { return this->priceB; }
int hotel::getPriceC() { return this->priceC; }
void hotel::setPriceA(const int& price) { this->priceA = price; }
void hotel::setPriceB(const int& price) { this->priceB = price; }
void hotel::setPriceC(const int& price) { this->priceC = price; }
void hotel::totalBill(const string& id) {
    int count = 0;
    int bill;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            count++;
            showMemberData(i);
            if (v[i]->getRoomType() == typeA) {
                bill = v[i]->getRentDay() * priceA;
            }
            if (v[i]->getRoomType() == typeB) {
                bill = v[i]->getRentDay() * priceB;
            }
            if (v[i]->getRoomType() == typeC) {
                bill = v[i]->getRentDay() * priceC;
            }
            cout << "Total bill: " << bill << endl;
        }
    }
    if (count == 0) {
        cout << "Can not find person has ID: " << id << " in list!" << endl;
    }
}
void hotel::addData() {
    int a;
    do {
        cout << "1-Type Room A - 2-Type Room B - 3-Type Room C - 0-Back: ";
        cin >> a;
    } while ((a < 0) || (a > 3));
    if (a == exit_t) { return; }
    person* p = new person;
    p->insertData();
    if (a == roomA_t) {
        p->setRoomType(typeA);
    }
    else if (a == roomB_t) {
        p->setRoomType(typeB);
    }
    else if (a == roomC_t) {
        p->setRoomType(typeC);
    }
    p->showInfo();
    v.push_back(p);
    int q;
    cout << "Ban co muon nhap them? 1-Yes/0-No: "; cin >> q;
    if (q == yes) {
        hotel::addData();
    }
}
void hotel::delData(const string& id) {
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            count++;
            person* tmp = v[i];
            v.erase(v.begin() + i);
            delete(tmp);
            i--;
        }
    }
    if (count == 0) {
        cout << "Can not find person has ID: " << id << " in list!" << endl;
        return;
    }
    cout << "Delete done!" << endl;
}
void hotel::showMemberData(const unsigned int& index) {
    if (v.empty()) {
        // cout << "No data in list!"<<endl;
        return;
    }
    if (index < v.size()) {
        v[index]->showInfo();
    }
}
void hotel::findData(const string& id) {
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            cout << i + 1 << ". ";
            count++;
            showMemberData(i);
        }
    }
    if (count == 0) {
        cout << "Can not find person has ID: " << id << " in list!" << endl;
    }
}
void hotel::showList() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << ". ";
        showMemberData(i);
    }
}
void hotel::showType(const int& type) {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    int count = 0;
    if (type == 0) {
        showList();
    }
    else if (type == roomA_t) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getRoomType() == typeA) {
                count++;
                cout << i + 1 << ". ";
                showMemberData(i);
            }
        }
        if (count == 0) {
            cout << "No data to show!" << endl;
        }
    }
    else if (type == roomB_t) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getRoomType() == typeB) {
                count++;
                cout << i + 1 << ". ";
                showMemberData(i);
            }
        }
        if (count == 0) {
            cout << "No data to show!" << endl;
        }
    }
    else if (type == roomC_t) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getRoomType() == typeC) {
                count++;
                cout << i + 1 << ". ";
                showMemberData(i);
            }
        }
        if (count == 0) {
            cout << "No data to show!" << endl;
        }
    }
    else { return; }
}
