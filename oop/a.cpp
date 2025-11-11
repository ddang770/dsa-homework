#include <bits/stdc++.h>
using namespace std;

//encapsulation
//get & set
//ham tao & ham huy: constructor
//con tro this
//Nap chong toan tu
//Ham ban
//object attribute
//class attribute: static

class SanPham{
private:
	string ma, ten;
	double gia;
	static int count;
public:
	void hienthi();
	SanPham(){
		ma = "SP001";
		ten = "Ban phim co";
		gia = 300000;
		++count;
	}
	SanPham(string ma, string ten, double gia){
		this->ma = ma; this->ten=ten; this->gia=gia;
		++count;
	}
	~SanPham(){
		cout<<"destructor dc goi\n";
	}
	static int getCount(){
		return count;
	}

	friend void inThongtin(SanPham s); // Hàm bạn có thể truy cập được data private

	double operator + (SanPham b){ // Nạp chồng toán tử
		double tonggia;
		tonggia = this->gia + b.gia;
		return tonggia;
	}

	friend ostream& operator << (ostream& out, SanPham x){ // viết cout bằng nạp chồng toán tử <<
		out<<x.ma<<" "<<x.ten<<" "<<x.gia<<endl;
		return out;
	}
	friend istream& operator >> (istream& in, SanPham& x){
		getline(in, x.ma);
		getline(in, x.ten);
		in>> x.gia;
		return in;
	}
};

void SanPham::hienthi(){
	cout<<this->ma<<" "<<this->ten<<" "<<this->gia<<endl;
}

void inThongtin(SanPham s){
	cout<<s.ma<<" "<<s.ten<<" "<<s.gia<<endl;
}

int SanPham::count = 0;

int main() {
	// SanPham s; // SanPham: class, s: object
	// cin >> s;
	SanPham t("SP002", "Quan jean", 10000);
	inThongtin(t);
	// cout << t;
	// SanPham b("SP003", "Man hinh", 20000);
	// cout<<t+b<<endl;
	// cout<< s;
	// cout<<s.getCount()<<endl;
	// cout<<SanPham::getCount()<<endl;
	return 0;
}