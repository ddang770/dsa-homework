#include <bits/stdc++.h>
using namespace std;

int doUuTien(char c){
	if(c=='^')
		return 3;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	return 0;
}

string infixToPostfix(string infix){
	stack<char> st;
	string postfix="";
	//duyet qua tat ca ki tu trong infix
	for(int i=0; i<infix.length(); i++){
		char c =infix[i];

		if(isdigit(c))
			postfix+=c;
		else if(c=='(')
			st.push('(');
		else if(c==')'){
			while(st.top() != '('){
				postfix+=st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while(!st.empty() && doUuTien(c)<=doUuTien(st.top())){
				postfix+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	//xu ly not toan tu con thua trong stack
	while(!st.empty()){
		postfix+=st.top();
		st.pop();
	}

	return postfix;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string infix="(5+3)*2-8/4";
	infixToPostfix(infix);
	cout << "infix: " << infix << endl;
    cout << "postfix: " << infixToPostfix(infix)<<endl;

	return 0;
}