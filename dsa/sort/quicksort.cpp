#include <bits/stdc++.h>
using namespace std;

void QuickSort (int a[], int L, int R)
{
	int x=a[(L+R)/2] ; //tìm phan tu key o giua
	int i=L; //i luu vi tri ben trai cua mang
	int j=R; // j luu vi tri ben phai
	//while phân hoach mang thanh 3 phan
	while (i <= j) {
        while (a[i] < x)  i++;
        while (a[j] > x)  j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
	
	if(L<j) QuickSort(a, L, j); //de quy cho mang ben trai
	if(i<R) QuickSort(a, i, R); //de quy cho mang ben phai
}


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[] = {3,2,5,1,6,4,8,9};
	QuickSort(a,0,7);
	for(int x: a){
		cout<<x<<" ";
	}

	return 0;
}