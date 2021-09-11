#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> v[N];
vector<bool> visited (N,false);
vector<int> conncomp(N,-1);

void dfs(int n, int count){
    visited[n]=1;
    conncomp[n]=count;
    for(auto x: v[n]){
        if(!visited[x]) dfs(x,count);
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
	int count=0;
	vector<int> s;
	for(int i=1;i<=n;i++){
	    if(!visited[i]){
	        count++;
	        s.push_back(i);
	        dfs(i,count);
	    } 
	}
	cout<<count-1<<endl;
	for(int i=0;i<s.size()-1;i++){
	        cout<<s[i]<<" "<<s[i+1]<<endl;
	}
	
	return 0;
}
