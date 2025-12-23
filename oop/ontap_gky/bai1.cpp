#include <iostream>
#include <stdexcept>
using namespace std;

int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = (mau == 0) ? 1 : mau;
        rutGon();
    }

    ~PhanSo() {
    }

    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
        } while (mauSo == 0);
        rutGon();
    }

    void xuat() const {
        if (mauSo == 1)
            cout << tuSo;
        else
            cout << tuSo << "/" << mauSo;
    }

    void rutGon() {
        int ucln = UCLN(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
    }

    PhanSo operator+(const PhanSo& ps) {
        return PhanSo(
            tuSo * ps.mauSo + ps.tuSo * mauSo,
            mauSo * ps.mauSo
        );
    }

    PhanSo operator-(const PhanSo& ps) {
        return PhanSo(
            tuSo * ps.mauSo - ps.tuSo * mauSo,
            mauSo * ps.mauSo
        );
    }

    PhanSo operator*(const PhanSo& ps) {
        return PhanSo(
            tuSo * ps.tuSo,
            mauSo * ps.mauSo
        );
    }

    PhanSo operator/(const PhanSo& ps) {
    	if (ps.tuSo == 0) {
	        throw runtime_error("Loi: Chia cho phan so bang 0");
	    }
        return PhanSo(
            tuSo * ps.mauSo,
            mauSo * ps.tuSo
        );
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();

    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    cout << "\nTong: ";
    (ps1 + ps2).xuat();

    cout << "\nHieu: ";
    (ps1 - ps2).xuat();

    cout << "\nTich: ";
    (ps1 * ps2).xuat();

    cout << "\nThuong: ";
    (ps1 / ps2).xuat();

    return 0;
}

