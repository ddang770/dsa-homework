#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void duyet(node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next; // cho head chuyen sang node ke tiep
	}
}

node *themdau(node *head, int x){
	// 1. Cap phat dong node moi
	node *newNode = new node;
	newNode->data = x; newNode->next = NULL;
	// 2. Tro node moi den head
	newNode->next = head;
	// 3. Cap nhat head thanh newNode
	head = newNode;
	return head;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	node *head = NULL;
	for (int i=0; i<=10; i++){
		head = themdau(head, i);
	}
	duyet(head);

	return 0;
}