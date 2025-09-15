#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

node *taoNode(int data){
	node *p = new node;
	p->data = data;
	p->next = nullptr;
	return p;
}

int top(node *st){
	return st->data;
}

void push(node *&st, int data){
	node *p = taoNode(data);
	if(st==nullptr){
		st=p;
	}
	else {
		p->next = st;
		st=p;
	}
}

void pop(node *&st){
	node *p = st;
	st = st->next;
	delete p;
}

void duyet(node *st){
	while(st!=nullptr){
		cout<<st->data<<" ";
		st=st->next;
	}
}

void nhiphan(node *&st, int x){
	while(x!=0){
		push(st, x%2);
		x/=2;
	}
	while(st!=nullptr){
		cout<<top(st);
		pop(st);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	node *stack = nullptr;
	nhiphan(stack, 50);

	return 0;
}