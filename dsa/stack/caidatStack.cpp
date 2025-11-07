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

bool isEmpty(node *st){
	if(st!=nullptr) return false;
	return true;
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
	if(isEmpty(st)){
		cout<<"dsach rong\n";
		return;
	}
	node *p = st;
	st = st->next;
	delete p;
}

void duyet(node *st){
	while(st!=nullptr){
		cout<<st->data<<" ";
		st=st->next;
	}
	return;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	node *stack = nullptr;
	// for(int i=0;i<10;i++){
	// 	push(stack, i+1);
	// }
	pop(stack);
	//pop(stack);
	//cout<< top(stack)<<endl;
	//duyet(stack);

	return 0;
}