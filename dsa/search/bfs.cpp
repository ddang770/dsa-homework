#include <bits/stdc++.h>
using namespace std;

int n, m; //n la so dinh, m la so canh
vector<int> adj[1001];
bool visited[1001]={};

void inp(){
	cin>>n>>m;
	for(int i=0; i<m ;i++){
		int x, y; cin>>x>>y;
		adj[x].push_back(y);
		//adj[y].push_back(x);
		// vidu: adj[1] = [2, 3, 5]
	}
}

void bfs(int u){
	// Buoc khoi tao
	queue<int> q;
	q.push(u);
	visited[u] = true;
	// Buoc lap
	while(!q.empty()){
		int v = q.front(); // lay ra dinh o dau hang doi
		q.pop();
		cout<<v<<" "; // tham dinh
		for(int n: adj[v]){ // duyet cac dinh ke
			if(!visited[n]){
				q.push(n);
				visited[n] = true;
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inp();
	bfs(1);

	return 0;
}