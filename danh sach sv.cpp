#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct SinhVien {
    string hoten;
    string masv;
    int tuoi;
};

int main() {
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    // Cap phat mang dong cho n sinh vien
    SinhVien* dsSinhVien = new SinhVien[n];

    // Nhap thong tin cho cac sinh vien
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << ":" << endl;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, dsSinhVien[i].hoten);
        cout << "Ma sinh vien: ";
        getline(cin, dsSinhVien[i].masv);
        cout << "Tuoi: ";
        cin >> dsSinhVien[i].tuoi;
    }

    // Xuat danh sach sinh vien
    cout << "Danh sach sinh vien vua nhap:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":" << endl;
        cout << "Ho ten: " << dsSinhVien[i].hoten << endl;
        cout << "Ma sinh vien: " << dsSinhVien[i].masv << endl;
        cout << "Tuoi: " << dsSinhVien[i].tuoi << endl;
    }

    // Tim sinh vien co ten la "Tu"
    cout << "Sinh vien co ten la \"Tu\":" << endl;
    for (int i = 0; i < n; i++) {
        if (dsSinhVien[i].hoten.find("Tu") != string::npos) {
            cout << "Sinh vien " << i + 1 << ":" << endl;
            cout << "Ho ten: " << dsSinhVien[i].hoten << endl;
            cout << "Ma sinh vien: " << dsSinhVien[i].masv << endl;
            cout << "Tuoi: " << dsSinhVien[i].tuoi << endl;
        }
    }

    // Sap xep sinh vien theo thu tu tang dan cua ho ten
    sort(dsSinhVien, dsSinhVien + n, [](SinhVien sv1, SinhVien sv2) 
	{
        return sv1.hoten < sv2.hoten;
    });

    // Xuat danh sach sinh vien sau khi sap xep
    cout << "Danh sach sinh vien sau khi sap xep theo thu tu tang dan cua ho ten:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":" << endl;
        cout << "Ho ten: " << dsSinhVien[i].hoten << endl;
        cout << "Ma sinh vien: " << dsSinhVien[i].masv << endl;
        cout << "Tuoi: " << dsSinhVien[i].tuoi << endl;
    }

    // Giai phong bo nho
    delete[] dsSinhVien;

    return 0;
}

