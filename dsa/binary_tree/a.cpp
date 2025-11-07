#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    int age;
    string ten;
    SinhVien() {}
    SinhVien(int age, string ten) {
        this->age = age;
        this->ten = ten;
    }
};

bool cmp(const pair<int, SinhVien>& a, const pair<int, SinhVien>& b) {
    return a.second.age < b.second.age;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    map<int, SinhVien> m;

    // Nhập dữ liệu
    for (int i = 0; i < 3; ++i) {
        int age;
        string ten;
        cin >> age >> ten;
        m[i] = SinhVien(age, ten);  // gán trực tiếp object, không cần new
    }

    // Chuyển sang vector để sort theo age
    vector<pair<int, SinhVien>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    // In kết quả sau khi sắp xếp
    for (auto& p : v) {
	    cout << p.second.age << " " << p.second.ten << '\n';
	}

    return 0;
}