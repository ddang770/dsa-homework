#include <bits/stdc++.h>
using namespace std;

void tim_max(int a[], int n){
	int max = a[0]; // o1
	int loc; // o1
	for (int i=1;i<n;i++){ //o(n)
		if (a[i]>max){ //01
			max = a[i]; //01
			loc = i; //01
		}
	}
	cout << "So lon nhat: " << max << endl; //01
	cout << "vi tri: " << loc << endl; //01
	// Do phuc tap 0(n)
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n];
	for (int i=0; i<n;i++){
		cin >> a[i];
	}
	int max = a[0]; // o1
	int loc; // o1
	for (int i=1;i<n;i++){ //o(n)
		if (a[i]>max){ //01
			max = a[i]; //01
			loc = i; //01
		}
	}
	cout << "So lon nhat: " << max << endl; //01
	cout << "vi tri: " << loc << endl; //01

	cout << "Complexity: O(n)\n";

	return 0;
}