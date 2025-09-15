#include <bits/stdc++.h>
using namespace std;

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
	int count = 0;
	for (int i=0;i<n;i++){
		if (a[i]>-1){
			count++;
		}
	}
	cout << "Co " << count << " so khong am" << endl;

	cout << "Complexity: O(n)\n";

	return 0;
}