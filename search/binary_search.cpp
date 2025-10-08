#include <bits/stdc++.h>
using namespace std;

// Binary search: yêu cầu dsach đã được sắp xếp tăng dần
// hàm sẽ trả về vị trí tìm thấy
int timkiemnhiphan(int a[], int left, int right, int socantim){
	if(left>right){
		cout<< "Khong tim thay\n";
		return -1;
	}
	int mid = (left+right)/2;
	if(a[mid] == socantim){
		return mid;
	}
	else if(a[mid] > socantim){ // Duyet ben trai mid
		timkiemnhiphan(a, left, mid-1, socantim);
	}
	else if(a[mid] < socantim){ // Duyet ben phai mid
		timkiemnhiphan(a, mid+1, right, socantim);
	}
}
int main() {
	int n = 5;
	int a[n]={1,2,3,4,5};
	cout<<timkiemnhiphan(a, 0, n-1, 5)<<endl;
	return 0;
}