#include <bits/stdc++.h>
using namespace std;

int dodai(int n){
	int res=0;
	while(n!=0){
		n/=10;
		res++;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b;cin>>a>>b;
	int len = b-a+1;
	bool check = false;
	for (int i=0;i<len;i++){
		int c=a+i;
		if(c%2==1){
			int n=dodai(a+1);
			int max=(c/(int)pow(10,n/2))%10;
			while(c!=0){
				if(c%10 > max){
					break;
				}
				c/=10;
			}
			cout<<c<<" ";
		}
	}
	if(!check){
		cout<<"28tech\n";
	}

	return 0;
}