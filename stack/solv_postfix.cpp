#include <bits/stdc++.h>
using namespace std;
/*
	Tinh gia tri cua bieu thuc Postfix
*/

float Pop(stack<float> &s){
	float res = s.top();
	s.pop();
	return res;
}

float tinhPostfix(string s){
	stack<float> st;
	float a, b, res;
	int len = s.length();
	for(int i=0;i<len;i++){
		char c = s[i];

		if(!isdigit(c)){ // neu ko phai toan hang
			// a = Pop(st);
			// b = Pop(st);
			a=st.top(); st.pop();
			b=st.top(); st.pop();
			switch(c)
			{
			case '+':
				res = b+a;
				break;
			case '-':
				res = b-a;
				break;
			case '*':
				res = b*a;
				break;
			case '/':
				res = b/a;
				break;
			// case '%':
			// 	res = b%a;
			// 	break;
			case '^':
				res = pow(b,a);
				break;
			}
			st.push(res);
		}
		else {
			st.push(c - '0');
		}
	}
	res = Pop(st);
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string postfix = "537-/215+*-";
	cout<<tinhPostfix(postfix)<<endl;

	return 0;
}
