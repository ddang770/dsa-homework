#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

class nhansu{
protected:
	string manv, hoten;
	int namsinh;
public:
	void nhap(){
		getline(cin, manv);
		getline(cin, hoten);
		cin>>namsinh;
		cin.ignore();
	}
	void xuat(){
		cout<<"manv: "<<manv<<endl;
		cout<<"hoten: "<<hoten<<endl;
		cout<<"namsinh: "<<namsinh<<endl;
	}
};

class canbo: public nhansu{
private:
	ll luongcoban, luong;
	float hesoluong;
public:
	void nhap(){
		nhansu::nhap();
		cin>>luongcoban>>hesoluong;
		cin.ignore();
	}
	void xuat(){
		nhansu::xuat();
		//cout<<"luongcoban: "<<luongcoban<<endl<<"hesoluong: "<<hesoluong<<endl;
		cout<<"luong: "<<luong<<endl;
	}
	ll getLuong(){
		return luong;
	}
	void tinhLuong(){
		luong = luongcoban*hesoluong;
	}
};

bool cmp(canbo a, canbo b){
	return a.getLuong() > b.getLuong();
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n; cin>>n;
	cin.ignore();
	canbo a[n];
	for(int i=0;i<n;i++){
		a[i].nhap();
		a[i].tinhLuong();
	}
	sort(a,a+n,cmp); // sort(begin, end, compare);
	for(int i=0;i<n;i++){
		a[i].xuat();
		cout<<"----------------\n";
	}
	return 0;
}