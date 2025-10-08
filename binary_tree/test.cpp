/*
	Binary tree - cay nhi phan
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	// contructor
	node(int x){
		data =x;
		left=right=NULL;
	}
};

// Hàm thêm node mới vào sau node có giá trị x (làm con phải)
bool themNodeSauX(node *root, int x, int newValue){ // true or false
	if (root == nullptr) return false;

    if (root->data == x) {
    	if(root->data < newValue){ // them vao ben phai
    		if (root->right == nullptr) {
	            root->right = new node(newValue);
	            return true;
	        } else {
	            // Đã có con phải → không thêm
	            return false;
	        }
    	}
    	else if(root->data > newValue){ // them vao ben trai
    		if (root->left == nullptr) {
	            root->left = new node(newValue);
	            return true;
	        } else {
	            // Đã có con trai → không thêm
	            return false;
	        }
    	}      
    }
    // Duyệt cây để tìm node có giá trị x
    return themNodeSauX(root->left, x, newValue) || themNodeSauX(root->right, x, newValue);
}

void duyettruoc(node *root){ // NODE-LEFT-RIGHT
	if(root!=NULL){
		cout<< root->data<<" "; // NODE
		duyettruoc(root->left); // LEFT
		duyettruoc(root->right); // RIGHT
	}
}

void duyetgiua(node *root){ // LEFT-NODE-RIGHT
	if(root!=NULL){
		duyetgiua(root->left);
		cout << root->data<<" ";
		duyetgiua(root->right);
	}
}

void duyetsau(node *root){ // LEFT-RIGHT-NODE
	if(root!=NULL){
		duyetsau(root->left);
		duyetsau(root->right);
		cout<<root->data<<" ";
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	node *root = new node(1);

	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

    if (themNodeSauX(root, 7, -1)) {
        cout << "Da them node " << newValue << " vao sau node " << x << "." << endl;
    } else {
        cout << "Khong the them node moi (node " << x << " khong ton tai hoac da co con phai)." << endl;
    }


    
    duyetgiua(root);

	return 0;
}