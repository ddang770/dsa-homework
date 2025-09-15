#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

// tao danh sach
struct LIST {
	node *head;
	node *tail;
};

// ham cap phat dong
node *taoNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->next = nullptr;
	return newNode;
}

void duyet(LIST &l){
	node *tmp = l.head;
	while(tmp != nullptr){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void themdau(LIST &l, int x){
	node *newNode = taoNode(x);
	if(l.head == nullptr){
		l.tail = newNode;
	}
	newNode->next = l.head;
	l.head = newNode;
}

void themgiua(LIST &l, int len, int n, int x){
	if(n<1 || n>len){
		cout<< "vi tri chen ko hop le\n";
		return;
	}
	node *newNode = taoNode(x);
	node *tmp = l.head;
	for(int i=0; i<n;i++){
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}

void xoagiua(LIST &l, int len, int n){
	if(n<1 || n>len){
		cout<< "vi tri xoa ko hop le\n";
		return;
	}
	node *tmp = l.head;
	for(int i=0; i<n-1;i++){
		tmp = tmp->next;
	}
	node *delNode = tmp->next;
	tmp->next = delNode->next;
	delete delNode;
}

void xoadau(LIST &l){
	if(l.head==nullptr){
		cout << "danh sach rong\n";
		return;
	}
	node *delNode = l.head;
	l.head = delNode->next;
	delete delNode;
}

void xoacuoi(LIST &l){
	if(l.head==nullptr){
		cout << "danh sach rong\n";
		return;
	}
	node *tmp = l.head;
	while(tmp->next->next != nullptr){
		tmp = tmp->next;
	}
	node *delNode = tmp->next;
	tmp->next = nullptr;
	l.tail = tmp;
	delete delNode;
}

void timkiem(LIST &l, int x){
	node *tmp = l.head;
	while(tmp!=nullptr){
		if(tmp->data==x){
			cout<< "tim thay "<<x<< " trong dsach\n";
			return;
		}
		tmp=tmp->next;
	}
	cout<<"ko tim thay "<<x<< " trong dsach\n";
}

void sapxep(LIST &l){
	for(node *i = l.head; i !=nullptr; i=i->next){
		node *minNode = i;
		for(node *j=i->next; j!=nullptr; j=j->next){
			if(minNode->data > j->data){
				minNode = j;
			}
		}
		int tmp = minNode->data;
		minNode->data = i->data;
		i->data = tmp;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int len; cin >>len;
	LIST l;
	l.head = nullptr;
	l.tail = nullptr;
	for(int i=0; i < len; i++){
		int n; cin>>n;
		themdau(l, n);
	}
	sapxep(l);
	duyet(l);
	//themgiua(l, len, 2, 18);
	//xoagiua(l, len, 1);
	//xoadau(l);
	//xoacuoi(l);
	//duyet(l);
	//timkiem(l, 1);
	return 0;
}