#include <bits/stdc++.h>
using namespace std;

class SinhVien{
private:
	string name;
public:
	SinhVien(){}
	
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
};
class person{
private:
	SinhVien u;
public:
friend void inThongtin(person s){
	cout<<s.u.getName()<<endl;

}
};

int main() {
	person a;
	
	inThongtin(a);
	return 0;
}