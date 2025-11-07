#include <bits/stdc++.h>
using namespace std;

struct node{
	char val;
	node *left;
	node *right;
	node(char c){
		val=c;
		left=right=nullptr;
	}
};

node *bst(string pf){
	stack<node*> s;
	node *a, *b, *res;
	for(char c:pf){
		node *p=new node(c);
		if(!isdigit(c)){
			a=s.top();s.pop(); //right
			b=s.top();s.pop(); //left
			p->right=a;
			p->left=b;
		}
		s.push(p);
		
	}
	res=s.top();
	s.pop();
	return res;
}

void duyet(node *root){
	if(root!=nullptr){
		cout<<root->val<<" ";
		duyet(root->left);
		duyet(root->right);
	}
}

int main() {
	#ifndef ONLINE_JUDGE //xóa từ #ifndef đến #endif để chạy code
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string postfix="53+2*84/-";
	node *root = bst(postfix);
	duyet(root);
	cout<<endl;

	return 0;
}