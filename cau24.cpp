#include <bits/stdc++.h>
using namespace std;

long giaithua(int n){
	if (n==0){
		return 1;
	}
	return n*giaithua(n-1);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x; cin>> x;
	long ex = 1;

	return 0;
}