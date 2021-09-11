#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> v[N];


pair<int, int> bfs(int node){
    queue<pair<int,int>> q;
    q.push({node,0});
    pair<int, int> j;
    vector<bool> visited (N,false);
    
    while(!q.empty()){
        j=q.front(); q.pop();
        visited[j.first]=true;
        for(auto n: v[j.first]){
            if(!visited[n]) q.push({n,j.second+1});
        }
    }
    return j;
}

int main() {
	// your code goes here
	int n,x,y;  cin>>n;
	for(int i=1;i<n;i++){
	    cin>>x>>y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	
	pair<int, int> p1 = bfs(1);
	pair<int, int> p2 = bfs(p1.first);
	cout<<p2.second;
	
	return 0;
}