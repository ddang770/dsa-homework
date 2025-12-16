#include <iostream>
#include <algorithm>
using namespace std;

class thisinh{
	private:
		string ma, hoten;
		float toan, ly, hoa;
	public:
		void nhap(){
			cout<<"Masv: ";getline(cin, ma);
			cout<<"Ho ten: ";getline(cin, hoten);
			cout<<"Diem toan: ";cin>>toan;
			cout<<"Diem ly: ";cin>>ly;
			cout<<"Diem hoa: ";cin>>hoa;
			cin.ignore();
		}
		void xuat(){
			cout<<"Masv: "<<ma<<endl;
			cout<<"Ho ten: "<<ma<<endl;
			cout<<"Diem toan, ly, hoa: "<<toan<<", "<<ly<<", "<<hoa<<endl;
		}
		float tongdiem(){
			return toan+ly+hoa;
		}
};

bool cmp(thisinh &a, thisinh &b){
	return a.tongdiem()>b.tongdiem();
}

int main(){
	int n;cout<<"So luong thisinh: ";cin>>n;
	cin.ignore();
	thisinh *a = new thisinh[n];
	for(int i=0;i<n;i++)
		a[i].nhap();
	sort(a, a+n, cmp);
	cout<<"\n---Thi sinh co tong diem cao nhat:---\n";
	a[0].xuat();
	delete[] a;
	return 0;
}
