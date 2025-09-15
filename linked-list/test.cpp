#include <bits/stdc++.h>
using namespace std;

void nn(int* n){
	cout << n <<endl;
}
void nnn(int &n){
	cout << n <<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 10;
	nn(&n);
	nnn(n);

	return 0;
}