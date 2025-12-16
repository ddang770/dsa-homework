#include <iostream>
using namespace std;

class matran{
	private:
		int capmatran, a[100][100];
	public:
		void nhap(){
			cout<<"Cap ma tran: ";cin>>capmatran;
			cout<<"Nhap cac ptu: ";
			for(int i=0;i<capmatran;i++)
				for(int j=0;j<capmatran;j++)
					cin>>a[i][j];
		}
		void xuat(){
			cout<<"--------Ma tran:--------\n";
			for(int i=0;i<capmatran;i++){
				for(int j=0;j<capmatran;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}
		int dcheochinh(){
			int tong=0;
			for(int i=0;i<capmatran;i++)
				tong+=a[i][i];
			return tong;
		}
		int dcheophu(){
			int tong=0;
			for(int i=0;i<capmatran;i++)
				tong+=a[i][capmatran-1-i];
			return tong;
		}
};

int main(){
	matran a;
	a.nhap();
	a.xuat();
	cout<<"Tong dcheo chinh: "<<a.dcheochinh()<<endl;
	cout<<"Tong dcheo phu: "<<a.dcheophu()<<endl;
}
