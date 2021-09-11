#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
vector<int> v[N];
bool visited[N];
int subtree[N];

int dfs(int x){
    visited[x]=true;
    int total=1;
    for(auto p: v[x]){
        if(visited[p]) continue;
        total+=dfs(p);
    }
    subtree[x]=total;
    return subtree[x];
}

int main() {
	// your code goes here
	int n,x;  cin>>n;
	
	for(int i=2;i<=n;i++){
	    cin>>x;
	    v[x].push_back(i);
	    v[i].push_back(x);
	}
	
	dfs(1);
    
    for(int i=1;i<=n;i++) cout<<subtree[i]-1<<" ";
    
	return 0;
}
