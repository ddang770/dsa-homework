#include<iostream>
using namespace std;
class matran{
	private:
		int hang;
		int cot;
		int a[100][100];
	public:
		void nhap(){
			cout<<"nhap so hang:";cin>>hang;
			cout<<"nhap so cot:";cin>>cot;
			for(int i=0;i<cot;i++)
				for(int j=0;j<hang;j++){
					cin>>a[i][j];
				}
			
		}
		void xuat(){
			for(int i=0;i<cot;i++){
				for(int j=0;j<hang;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}
		void tinhtongduongvien(){
		int tong=0;
		for(int i=0;i<cot;i++){
			for(int j=0;j<hang;j++){
				if(i==0||j==0||i<cot-1||j<hang-1)
					tong+=a[i][j];
			}
			
		}
		cout<<"tong duong vien:"<<tong<<endl;
	}
};
	

int main(){
	matran a;
	a.nhap();
	a.xuat();
	a.tinhtongduongvien();
}
	
	
	
