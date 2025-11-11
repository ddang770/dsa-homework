#include <bits/stdc++.h>
using namespace std;

class Person{
private:
	string name, address;
public:
	Person(){}
	Person(string name, string address){
		this->name = name;
		this->address = address;
	}
	string getName(){
		return name;
	}
	void setName(){
		getline(cin, name);
	}
	string getAddress(){
		return address;
	}
	void setAddress(){
		getline(cin, address);
	}
	void nhap(){
		getline(cin, name);
		getline(cin, address);
	}
};

class SinhVien: public Person{
private:
	double gpa;
public:
	SinhVien(){}
	SinhVien(string name, string address, double gpa):Person(name, address){
		this->gpa = gpa;
	}
	double getGpa(){
		return gpa;
	}
	void setGpa(){
		cin>>gpa;
	}
	void nhap(){	// function overriding
		Person::nhap();
		cin>>gpa;
	}
};

int main() {
	SinhVien a("Nguyen Van A", "Ha Noi", 3.5);
	cout<<a.getName()<<" "<<a.getAddress()<<" "<<a.getGpa()<<endl;
	return 0;
}