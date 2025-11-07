#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

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

	node *head = new node;
	head->data = 1;
	head->next = NULL;
	node test;
	test.data = 100;
	test.next = head;
	cout<<test.data<<" "<<test.next<<endl;
	cout<<head<<endl;

	return 0;
}