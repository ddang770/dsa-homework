#include <iostream>
#include <algorithm>
using namespace std;

int ucln(int a, int b){ // tu, mau
	if(b==0) return a;
	return ucln(b, a%b);
}

class PS{
private:
	int tu, mau;
public:
	PS(){};
	PS(int t, int m): tu(t), mau(m){}
	void nhap (){
		cin>>tu>>mau;
	}
	void xuat(){
		cout<<tu<<"/"<<mau<<endl;
	}
	void toigian(){
		int u = ucln(tu, mau);
		this->tu = tu/u;
		this->mau = mau/u;
	}
	friend void sxtangdan(PS a[]);

	friend bool operator > (PS a, PS b){
		return (float)a.tu/a.mau > (float)b.tu/b.mau;
	}
	friend PS operator + (PS a, PS b){
		PS kq(a.tu*b.mau+b.tu*a.mau, a.mau*b.mau);
		kq.toigian();
		return kq;
	}
	friend ostream& operator << (ostream& out, PS a){
		out<<a.tu<<"/"<<a.mau;
		return out;
	}
};

void sxtangdan(PS a[]){
	for(int i=0;i<5-1;i++)
		for(int j=i;j<5;j++){
			if(a[i]>a[j])
				swap(a[i], a[j]);
		}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	PS a[5];
	for(int i=0;i<5;i++){
		a[i].nhap();
		a[i].toigian();
	}
	PS kq = a[0] + a[1];
	kq.xuat();
	for(PS x:a)
		cout<<x<<endl;
}