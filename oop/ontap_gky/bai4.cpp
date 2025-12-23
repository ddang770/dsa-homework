#include <iostream>
using namespace std;

class DaThuc {
	private:
		int bac, *heso = new int[100];
	public:
		~DaThuc(){
			delete []heso;
		}
		void nhap(){
			cout<<"Bac da thuc: "; cin>>bac;
			for(int i=0;i<bac+1;i++){
				cout<<"He so bac "<<i<<": "; cin>>heso[i];
			}
		}
		void xuat(){
			// 2x^2+3x+4
			for(int i=bac;i>-1;i--){
				if(i>0){
					if(i!=1) cout<<heso[i]<<"x^"<<i;
					else cout<<heso[i]<<"x";
					cout<<"+";
				}
			}
			cout<<heso[0]<<endl;
		}
		DaThuc operator + (const DaThuc &dt){
			DaThuc kq;
			kq.bac = bac>dt.bac ? bac : dt.bac;
			for(int i=0;i<=kq.bac;i++){
				int a = i<=bac ? heso[i] : 0;
				int b = i<=dt.bac ? dt.heso[i] : 0;
				kq.heso[i]=a+b;
			}
			return kq;
		}
};

int main(){
	DaThuc a,b;
	cout<<"nhap da thuc a: \n";
	a.nhap();
	cout<<"nhap da thuc b: \n";
	b.nhap();
	a.xuat();
	b.xuat();
	cout<<"a + b= ";
	(a+b).xuat();
}
