#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> v[N];
vector<bool> visited (N,false);
int parent[N];

bool bfs(int node, int n){
    parent[1]=-1;
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int x=q.front(); 
        q.pop();
        if(x==n){
          return true;
        }
        for(auto p: v[x]){
            if(!visited[p]){
                visited[p]=1;
                parent[p]=x;
                q.push(p);
            }
        }
    }
    return false;
}

void printRoute(int n){
    stack<int> s;
    s.push(n);
    while(parent[n]!=-1){
        s.push(parent[n]);
        n=parent[n];
    }
    cout<<s.size()<<endl;
    int x;
    while(!s.empty()){
        x=s.top(); s.pop();
        cout<<x<<" ";
    }
}

int main() {
	// your code goes here
	int n,e,x,y;  cin>>n>>e;
	for(int i=0;i<e;i++){
	    cin>>x>>y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	if(!bfs(1,n))
	    cout<<"IMPOSSIBLE";
	else{
	    printRoute(n);
	}
	
	
	return 0;
}
