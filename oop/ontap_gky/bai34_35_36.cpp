#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
	------BAI 34, 35, 36------
*/

class sp1{
protected:
	int sothuc, soao;
public:
	sp1(){}
	sp1(int thuc, int ao){
		sothuc=thuc;soao=ao;
	}
	void nhap(){
		cout<<"Phan thuc: ";cin>>sothuc;
		cout<<"Phan ao: ";cin>>soao;
	}
	void in(){
		cout<<sothuc<<"+"<<soao<<"i"<<endl;
	}
	float tinhmodule(){
		return sqrt(sothuc*sothuc+soao*soao);
	}
};

class sp2:public sp1{
	public:
		sp2& operator = (sp2 &p){
			this->sothuc=p.sothuc;
			this->soao=p.soao;
			return this*;
		}
		bool operator > (sp2 &p){
			return this->tinhmodule() > p.tinhmodule();
		}
		bool operator < (sp2 &p){
			return this->tinhmodule() < p.tinhmodule();
		}
};

bool giamdan(sp2 &a, sp2 &b){
	return a>b;
}

bool tangdan(sp2 &a, sp2 &b){
	return a<b;
}
sp2 timmax(sp2 a[], int n){
	sp2 max = a[0];
	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
	return max;
}
sp2 timmin(sp2 a[], int n){
	sp2 min = a[0];
	for(int i=0;i<n;i++)
		if(a[i]<min)
			min=a[i];
	return min;
}

int main() {
	sp2 a[10];
	int n;
	do {
		cout<<"So luong: ";
		cin>>n;
	}while(n>10);
	for(int i=0;i<n;i++) a[i].nhap();
	sort(a, a+n, tangdan);
	cout<<"-------Sau khi sap xep-------\n";
	for(int i=0;i<n;i++) a[i].in();
	cout<<"Max: ";timmax(a,n).in();
	cout<<"Min: ";timmin(a,n).in();
	return 0;
}
