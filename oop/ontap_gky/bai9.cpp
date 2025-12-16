#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];
    string monHoc[5] = {
        "Toan", "Ly", "Hoa", "Van", "Anh"
    };

public:
    // Nh?p thông tin sinh viên
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 5; i++) {
            do {
                cout << "Nhap diem mon " << monHoc[i] << ": ";
                cin >> diem[i];
            } while (diem[i] < 0 || diem[i] > 10);
        }
    }

    // Xu?t thông tin sinh viên
    void xuat() const {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
        for (int i = 0; i < 5; i++) {
            cout << monHoc[i] << ": " << diem[i] << endl;
        }
        cout << "Diem trung binh: " << diemTrungBinh() << endl;
    }

    // Tính di?m trung bình
    float diemTrungBinh() const {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5;
    }

    // In các môn ph?i thi l?i
    void inMonThiLai() const {
        bool coThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                if (!coThiLai) {
                    cout << "\nSinh vien: " << hoTen << endl;
                    coThiLai = true;
                }
                cout << "  Mon thi lai: " << monHoc[i]
                     << " - Diem: " << diem[i] << endl;
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien sv[100];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        sv[i].nhap();
    }

    cout << "\n===== DANH SACH SINH VIEN PHAI THI LAI =====\n";
    for (int i = 0; i < n; i++) {
        sv[i].inMonThiLai();
    }

    return 0;
}

