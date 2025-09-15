#include <bits/stdc++.h>
using namespace std;

void thaphn(int sodia, char cot_ban_dau, char cot_trung_gian, char cot_chuyen_den){
	if (sodia==1){
		cout << "Chuyển đĩa 1 từ " << cot_ban_dau << " -> " << cot_chuyen_den << endl;
		return;
	}
	thaphn(sodia-1, cot_ban_dau, cot_chuyen_den, cot_trung_gian);
	cout << "Chuyển đĩa " << sodia << " từ " << cot_ban_dau << " -> " << cot_chuyen_den << endl;
	thaphn(sodia - 1, cot_trung_gian, cot_ban_dau, cot_chuyen_den);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// chuyen tu a -> c
	//thaphn(3, 'A', 'B', 'C');

	// chuyen tu a -> b
	thaphn(3, 'A', 'C', 'B');

	return 0;
}