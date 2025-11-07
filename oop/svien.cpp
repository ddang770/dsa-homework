#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string hoten, ngaysinh, gioitinh, lop;
    double diemtoan, diemly, diemhoa, dtb;
public:
    void nhap();
    void xuat();
    double diemtb();
    void chuyenhe4();
    double getDtb();
};

void SinhVien::nhap() {
    cin.ignore(); // bỏ ký tự xuống dòng còn lại sau khi nhập n
    //cout << "Nhap ho ten: ";
    getline(cin, hoten);
    //cout << "Nhap ngay sinh: ";
    getline(cin, ngaysinh);
    //cout << "Nhap gioi tinh: ";
    getline(cin, gioitinh);
    //cout << "Nhap lop: ";
    getline(cin, lop);
    //cout << "Nhap diem toan, ly, hoa: ";
    cin >> diemtoan >> diemly >> diemhoa;
}

double SinhVien::diemtb() {
    dtb = (diemtoan + diemly + diemhoa) / 3;
    return dtb;
}

double SinhVien::getDtb() {
    return dtb;
}

void SinhVien::xuat() {
    cout << "\nHo ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Gioi tinh: " << gioitinh << endl;
    cout << "Lop: " << lop << endl;
    cout << "Diem toan: " << diemtoan << ", Ly: " << diemly << ", Hoa: " << diemhoa << endl;
    cout << "Diem trung binh: " << dtb << endl;
}

void SinhVien::chuyenhe4() {
    cout << "Xep loai: ";
    if (dtb >= 8.5) cout << "A";
    else if (dtb >= 7) cout << "B";
    else if (dtb >= 5.5) cout << "C";
    else if (dtb >= 4) cout << "D";
    else cout << "F";
    cout << endl;
}

bool cmp(SinhVien a, SinhVien b) {
    return a.getDtb() > b.getDtb(); // giảm dần
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; cin >> n;
    vector<SinhVien> a(n);

    for (int i = 0; i < n; i++) {
        a[i].nhap();
        a[i].diemtb();
    }

    sort(a.begin(), a.end(), cmp);

    cout << "\nDANH SACH SAU KHI SAP XEP\n";
    for (int i = 0; i < n; i++) {
        a[i].xuat();
        a[i].chuyenhe4();
        cout << endl;
    }

    return 0;
}
