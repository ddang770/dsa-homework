#include <iostream>
#include <algorithm>
using namespace std;

int ucln(int a, int b){
	if(b==0) return a;
	return ucln(b, a%b);
}

class ps1{
protected:
	int tuso, mauso;
public:
	ps1(){}
	ps1(int tu, int mau){
		tuso=tu;mauso=mau;
	}
	void nhap(){
		cout<<"Tu so: ";cin>>tuso;
		do {
			cout<<"Mau so (!=0): ";cin>>mauso;
		}while(mauso==0);
	}
	void in(){
		cout<<tuso<<"/"<<mauso<<endl;
	}
	void toigian(){
		int u=ucln(tuso, mauso);
		tuso=tuso/u;
		mauso=mauso/u;
	}
};

class ps2:public ps1{
	public:
		ps2(){
			tuso=0;mauso=1;
		}
		ps2(int tu, int mau):ps1(tu, mau){}
		
		ps2& operator = (const ps2 &p){
			tuso=p.tuso;
			mauso=p.mauso;
			return *this;
		} 
		/* this = ps2*: con tro toi doi tuong hien tai
		 *this = ps2&: doi tuong hien tai */

		bool operator < (const ps2 &p) const{
		    return tuso * p.mauso < p.tuso * mauso;
		}
		bool operator > (const ps2 &p) const{
		    return tuso * p.mauso > p.tuso * mauso;
		}

		ps2 operator + (const ps2 &p){
			ps2 kq;
			kq.tuso=tuso*p.mauso+p.tuso*mauso;
			kq.mauso=mauso*p.mauso;
			kq.toigian();
			return kq;
		}
};

ps2 *timmax(ps2 a[], int n){
	ps2 *max=&a[0];
	for (int i=1;i<n;i++)
		if(*max<a[i])
			max=&a[i];
	return max;
}


int main() {
	ps2 a[10], b(1,2), c(1,4);
	int n;cout<<"So luong: ";cin>>n;
	for(int i=0;i<n;i++)
		a[i].nhap();
	ps2 tong;
	for(int i=0;i<n;i++)
		if(a[i]<b)
			tong=tong+a[i];
	cout<<"Max: ";
	timmax(a, n)->in();
	cout<<"Tong: ";
	tong.in();
	
	return 0;
}
