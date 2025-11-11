#include <bits/stdc++.h>
using namespace std;

class SinhVien{
private:
	string name, address;
public:
	SinhVien(string name, string address){
		this->name=name;
		this->address=address;
	}
	friend void inThongtin(SinhVien s){
		cout<<s.name<<", "<<s.address<<endl;
	}
};

int main() {
	SinhVien a("Nguyen Van A", "Ha Noi");
	inThongtin(a);
	return 0;
}