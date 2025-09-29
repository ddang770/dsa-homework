/*
	______________________
		MADE BY IAOX
	______________________
*/


#include <bits/stdc++.h>
using namespace std;

void bb_sort(vector<int> &v){
	int n =v.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(v[j]>v[j+1]) //tang dan
				swap(v[j], v[j+1]);
		}
	}
}

void sl_sort(vector<int> &v){
	int n=v.size();
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(v[min]>v[j])
				min=j;
		}
		swap(v[i], v[min]);
	}
}

// Lomuto
int partition(vector<int> &v, int l, int r){
	int pivot = v[r]; // phtu ben phai cung
	int i = l-1;
	for(int j=l;j<r;j++){
		if(v[j]<=pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	// dua chot ve giua
	i++;
	swap(v[i], v[r]);
	return i;
}

void quicksort(vector<int> &v, int l, int r){
	if(l>=r) return; // con 1 phtu thi return
	int pi = partition(v, l, r); //
	quicksort(v, l ,pi-1); // sort ben trai
	quicksort(v, pi+1 ,r); // sort ben phai
}

void insertionSort(vector<int> &v){
	int n= v.size();
	for(int i =1; i<n;i++){
		int j= i;
		while(j>0 && v[j-1]>v[j]){
			swap(v[j-1], v[j]);
			j--;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v={10, 7, 8, 9, 1, 5};
	int n = v.size();
	//bb_sort(v);
	//sl_sort(v);
	//quicksort(v, 0, n-1);
	insertionSort(v);
	for(int x:v){
		cout<<x<<" ";
	}
	return 0;
}