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
		ps2& operator = (const ps2 &p){
			tuso=p.tuso;
			mauso=p.mauso;
			return *this;
		} 
		/* this = ps2*: con tro toi doi tuong hien tai
		 *this = ps2&: doi tuong hien tai */
		 
//		void operator = (ps2 p){
//			this->tuso=p.tuso;
//			this->mauso=p.mauso;
//		}
		bool operator < (const ps2 &p) const{
			return (float)tuso/mauso < (float)p.tuso/p.mauso;
		}
		bool operator > (const ps2 &p) const{
			return (float)tuso/mauso > (float)p.tuso/p.mauso;
		}
};

bool tangdan(const ps2 &a, const ps2 &b){
    return a < b;
}
bool giamdan(const ps2 &a, const ps2 &b){
	return a>b;
}

ps2 *timmax(ps2 a[], int n){
	ps2 *max=&a[0];
	for (int i=1;i<n;i++)
		if(*max<a[i])
			max=&a[i];
	return max;
}
ps2 *timmin(ps2 a[], int n){
	ps2 *min=&a[0];
	for (int i=1;i<n;i++)
		if(*min>a[i])
			min=&a[i];
	return min;
}

int main() {
//	ps2 a,b;
//	b.nhap();
//	a=b; //a.operator=(b);
//	a.in();
//	b.in();

	ps2 a[10];
	int n;cout<<"So luong: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap pso thu "<<i+1<<":\n";
		a[i].nhap();
	}
	sort(a, a+n, tangdan);
	cout<<"--------Sau khi sxep: --------\n";
	for(int i=0;i<n;i++){
		a[i].in();
	}
	cout<<"Max: ";
	timmax(a, n)->in();
	cout<<"Min: ";
	timmin(a, n)->in();

//	int a=10;
//	int *b = &a;
//	int **c = &b;
//	cout<<*c<<endl;
//	cout<<&a<<endl;
	
	return 0;
}
