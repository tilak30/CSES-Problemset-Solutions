#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6;
vector<int> v[N];
vector<bool> visited (N,false);
vector<int> color(N,0);
 
bool dfs(int n, int col){
    visited[n]=1;
    color[n]=col;
    col = (col==1) ? 2 : 1;
    for(auto x: v[n]){
        if(!visited[x]){
             if(!dfs(x, col)) return false;
             for(auto y: v[x]){
                  if(color[y]==col) return false;
             }
        };
    }
    return true;
}
 
int main() {
	// your code goes here
	int n,e,x,y;  cin>>n>>e;
	for(int i=0;i<e;i++){
	    cin>>x>>y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	int count=0;
	for(int i=1;i<=n;i++){
	    if(!visited[i]){
	        if(!dfs(i,1)) {
	             cout<<"IMPOSSIBLE";
	             return 0;
	        };
	    } 
	}
	for (int i=1;i<=n;i++)
	     cout<<color[i]<<" ";
	
	return 0;
}
