#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

/*Để quản lý khách hàng đến thuê phòng của một khách sạn, người ta cần các thông tin sau:
Số ngày thuê, loại phòng, thông tin cá nhân của những người thuê phòng.
Biết rằng phòng loại A có giá 500$, phòng loại B có giá 300$ và loại C có giá 100$.
Với mỗi cá nhân cần quản lý các thông tin sau: Họ tên, tuổi, số chứng minh nhân dân.
Yêu cầu 1: Hãy xây dựng lớp Nguoi để quản lý thông tin cá nhân của những người thuê phòng.
Yêu cầu 2: Xây dựng lớp KhachSan để quản lý các thông tin về các phòng trong khác sạn.
Yêu cầu 3: Xây dựng các phương thức thêm mới, xoá khách theo số chứng minh nhân dân.
Tính tiền thuê phòng cho khách(xác định khách bằng số chứng minh nhân dân)
dựa vào công thức: (số ngày thuê * giá của từng loại phòng)*/

#define yes 1
#define no 0
typedef enum { cmd_exit, cmd_add, cmd_remove, cmd_find, cmd_showlist, cmd_totalBill }comand;
typedef enum { exit_t, roomA_t, roomB_t, roomC_t }type_t;

typedef enum { typeA, typeB, typeC }roomType;


void chuanhoaTen(string& a);
bool checkSameID(set<string> list, string id);
bool checkValidID(string id);
bool checkValidName(string name);

class myException :public exception {
    string msg;
public:
    myException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};


#endif