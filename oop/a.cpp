#include <bits/stdc++.h>
using namespace std;

//encapsulation
//get & set
//ham tao & ham huy: constructor
//con tro this

class SanPham{
private:
	string ma, ten;
	double gia;
public:
	void hienthi();
	SanPham(){
		ma = "SP001";
		ten = "Ban phim co";
		gia = 300000;
	}
	SanPham(string ma, string ten, double gia){
		this->ma = ma; this->ten=ten; this->gia=gia;
	}
};

void SanPham::hienthi(){
	cout<<this->ma<<" "<<this->ten<<" "<<this->gia<<endl;
}

int main() {
	SanPham s; // SanPham: class, s: object
	s.hienthi();
	SanPham t("SP002", "Quan jean", 10000);
	t.hienthi();
	return 0;
}