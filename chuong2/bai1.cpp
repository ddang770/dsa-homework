#include <bits/stdc++.h>
using namespace std;

void nhapmang(int a[], int n){
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
}

void duyetmang(int a[], int n){
	for (int i=0;i<n;i++){
		cout << a[i]<< " ";
	}
	cout << endl;
}

void themphtu(int a[], int &len, int x, int n){
	if (n>len){
		cout << "Mang co "<< len<< "phtu nen ko the them vao vtri "<<n<<endl;
	}
	for(int i=len; i >=n; i--){
		if (i>=n){
			a[i+1]= a[i];
		}
		if (i==n) {
			a[i]= x;
			len++;
			break;
		}
	}
}

void xoaphtu(int a[], int &len, int n){
	if (n>len){
		cout << "Mang co "<< len<< "phtu nen ko the xoa phtu o vtri "<<n<<endl;
	}
	for(int i=0; i<len-1; i++){
		if(i>=n){
			a[i] = a[i+1];
		}
	}
	len--;
}

void timphtu(int a[], int &len, int x){
	for(int i=0; i<len;i++){
		if(a[i]==x){
			cout <<"phan tu "<<x<<" co trong mang\n";
			return;
		}
	}
	cout <<"phan tu "<<x<<" ko co trong mang\n";
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[100], n; cin >>n;
	nhapmang(a, n);
	themphtu(a, n, 28, 2);
	duyetmang(a, n);
	xoaphtu(a, n, 3);
	duyetmang(a, n);
	timphtu(a, n, 28);

	return 0;
}