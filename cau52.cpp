#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n; cin >> x >> n;
	int a[n];
	for (int i=0; i<n;i++){
		cin >> a[i];
	}
	int count = 0;
	for (int i=0;i<n;i++){
		if (a[i]%x==0){
			count++;
			cout << a[i] << " ";
		}
	}
	cout << "\nCo " << count << " so chia het cho x=" << x << endl;

	cout << "Complexity: O(n)\n";

	return 0;
}