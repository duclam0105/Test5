#ifndef __HOTEL_H
#define __HOTEL_H

#include "Lib.h"
#include "person.h"

class hotel {
private:
    int priceA = 500, priceB = 300, priceC = 100;
    vector<person*> v;
public:
    int getPriceA();
    int getPriceB();
    int getPriceC();
    void setPriceA(const int&);
    void setPriceB(const int&);
    void setPriceC(const int&);
    void totalBill(const string&);
    void addData();
    void delData(const string&);
    void findData(const string&);
    void showType(const int&);
    void showList();
    void showMemberData(const unsigned int& index);
    int getSize() {
        return v.size();
    }
};

#endif // !__HOTEL_H
