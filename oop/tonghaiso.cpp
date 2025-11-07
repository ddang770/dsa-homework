#include <bits/stdc++.h>
using namespace std;

class tinhtong{
private:
	int a, b;
public:
	void nhap();
	void xuat();
};

void tinhtong::nhap(){
	cin>>this->a>>this->b;
}

void tinhtong::xuat(){
	cout<<this->a+this->b<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	tinhtong a;
	a.nhap();
	a.xuat();
	return 0;
}