#include "Lib.h"
#include "person.h"
#include "hotel.h"

set<string> listID;

int main() {
    int temp;
    hotel cs;
    while (true) {
        cout << "===================\n";
        cout << "1-Them moi khach\n2-Xoa khach\n3-Tim kiem\n4-Hien thi danh sach\n5-Tinh bill\n0-Thoat\nMoi ban nhap: ";
        cin >> temp;
        cout << "===================\n";
        switch (temp) {
        case cmd_exit: {
            cout << "Close the program..." << endl;
            system("cls");
            return 0;
        }
        case cmd_add:
            cs.addData();
            break;
        case cmd_remove: {
            string str;
            do {
                cout << "Nhap ID cua nguoi can xoa: ";
                cin >> str;
                // chuanhoaID(str);
                if (str == "0") break;
            } while (!checkValidID(str));
            cs.delData(str);
            break;
        }
        case cmd_find: {
            string str;
            do {
                cout << "Nhap ID cua nguoi can tim kiem: ";
                cin >> str;
                // chuanhoaID(str1);
                if (str == "0") break;
            } while (!checkValidID(str));
            cs.findData(str);
            break;
        }
        case cmd_showlist: {
            int tmp;
            cout << "0-All - 1-Type Room A - 2-Type Room B - 3-Type Room C: ";
            cin >> tmp;
            cs.showType(tmp);
            break;
        }
        case cmd_totalBill: {
            string str;
            do {
                cout << "Nhap ID cua nguoi can tim kiem: ";
                cin >> str;
                // chuanhoaID(str1);
                if (str == "0") break;
            } while (!checkValidID(str));
            cs.totalBill(str);
        }
        default:
            break;
        }
    }
    cout << "Close the program..." << endl;
    system("cls");
    return 0;
}
