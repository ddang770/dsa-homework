#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001]={};

/*
input:
9 9
1 2
1 3
1 5
2 4
3 6

output: 1 2 4 3 6 5 
*/

void inp(){
	cin>>n>>m;
	for(int i=0; i<m ;i++){
		int x, y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		// adj[1] = [2, 3, 5]
	}
}

void dfs(int u){
	cout<<u<<" ";
	visited[u] = true;
	for(int v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main() {
	inp();
	dfs(1);

	return 0;
}