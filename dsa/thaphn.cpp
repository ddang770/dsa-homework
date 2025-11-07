#include <bits/stdc++.h>
using namespace std;

void chuyen(int i, char a, char b){
	cout<<"Chuyển đĩa "<<i<<" từ "<<a<<" -> "<<b<<endl;
	return;
}

void thapHN(int i, char a, char b, char c){
	if (i==1){
		chuyen(1, a, c);
		return;
	}
	thapHN(i-1, a, c, b);
	chuyen(i, a, c);
	thapHN(i-1, b, a, c);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;

	char a='A', b='B', c='C';
	thapHN(n, a,b,c);
	

	return 0;
}