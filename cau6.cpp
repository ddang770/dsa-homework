#include <bits/stdc++.h>
using namespace std;

// thuat toan Euclid
int ucln(int a, int b) {
	if (b==0)
		return a;
	int r = a%b;
	return ucln(b, r);
}

// ucln(48, 18)
// → 48 % 18 = 12
// → ucln(18, 12)
//   → 18 % 12 = 6
//   → ucln(12, 6)
//     → 12 % 6 = 0
//     → ucln(6, 0) → return 6

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b; cin >> a >>b;
	cout << "UCLN cua " << a << " va " << b << " la " << ucln(a,b) << endl;
	cout << "Complexity: O(log(n))\n";

	return 0;
}