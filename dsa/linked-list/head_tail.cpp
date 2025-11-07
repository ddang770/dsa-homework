#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct LIST {
	node *head;
	node *tail;
};

void duyet(LIST l){
	if (l.head==NULL){
		cout << "Dsach rong\n";
	} 
	else {
		node *tmp = l.head;
		while(tmp != NULL){
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}

}

void themdau(LIST &l, int x){
	node *newNode = new node;
	newNode->data=x; newNode->next=NULL;
	if (l.head == NULL){
		l.tail = newNode;
	}
	newNode->next = l.head;
	l.head = newNode;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LIST l;
	l.head=NULL; l.tail=NULL;
	for(int i=0;i<=11;i++){
		themdau(l, i);
	}
	duyet(l);

	return 0;
}