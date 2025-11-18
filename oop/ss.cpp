#include <bits/stdc++.h>
using namespace std;

class SP{
private:
	float thuc, ao;
public:
	SP(){}
	SP(float t, float a):thuc(t), ao(a){}
	~SP(){}
	friend istream& operator >>(istream& in, SP &x);
	friend ostream& operator <<(ostream& out, SP x);
	SP operator + (SP b){
		return SP(thuc+b.thuc, ao+b.ao);
	}
	SP operator - (SP b){
		return SP(thuc-b.thuc, ao-b.ao);
	}
	SP operator * (SP b){
		return SP(thuc*b.thuc-ao*b.ao, thuc*b.ao+ao*b.thuc);
	}
	friend SP operator / (SP a, SP b) {
	    // Tính mẫu số: c² + d²
	    float mau = b.thuc * b.thuc + b.ao * b.ao;
	    
	    // Kiểm tra trường hợp chia cho 0
	    if (mau == 0) {
	        cout << "Loi: Khong the chia cho 0!" << endl;
	        return SP(0, 0); // Trả về số phức 0+0i
	    }
	    
	    // Tính phần thực: (ac + bd)/(c² + d²)
	    float thuc_moi = (a.thuc * b.thuc + a.ao * b.ao) / mau;
	    
	    // Tính phần ảo: (bc - ad)/(c² + d²)
	    float ao_moi = (a.ao * b.thuc - a.thuc * b.ao) / mau;
	    
	    return SP(thuc_moi, ao_moi);
	}
};

ostream& operator <<(ostream& out, SP x){ // in
	out<<x.thuc<<"+"<<x.ao<<"i";
	return out;
}
istream& operator >>(istream& in, SP &x){ // nhap
	in>>x.thuc>>x.ao;
	return in;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	SP a,b;
	cin>>a>>b;
	cout<<(a/b);
}