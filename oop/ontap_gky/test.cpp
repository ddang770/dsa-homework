#include <iostream>
using namespace std;

class Nguoi{
	protected:
		string hoten, gioitinh;
		int namsinh;
};

class SinhVien: virtual public Nguoi{
	protected:
		double diemtb;
};

class GiangVien: virtual public Nguoi{
	protected:
		string tenmon;
};

class TroGiang: public SinhVien, public GiangVien{
	protected:
		string tenkhoahoc;
	public:
		void nhap(){
			cout<<"Ho ten: "; getline(cin, hoten);
			cout<<"Gioi tinh: "; getline(cin, gioitinh);
			cout<<"Nam sinh: "; cin>>namsinh; cin.ignore();
			cout<<"Ten mon: "; getline(cin, tenmon);
			cout<<"Ten khoa hoc: "; getline(cin, tenkhoahoc);
		}
		void hien(){
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Gioi tinh: "<<gioitinh<<endl;
			cout<<"Nam sinh: "<<namsinh<<endl;
			cout<<"Ten mon: "<<tenmon<<endl;
			cout<<"Ten khoa hoc: "<<tenkhoahoc<<endl;
			cout<<endl;
		}
};

int main(){
	TroGiang *a;
	int n; cout<<"So luong: "; cin>>n; cin.ignore();
	a = new TroGiang[n];
	for(int i=0;i<n;i++)
		a[i].nhap();
	cout<<"-----Thong tin tro giang-----\n";
	for(int i=0;i<n;i++)
		a[i].hien();
		
	delete[] a;
}
