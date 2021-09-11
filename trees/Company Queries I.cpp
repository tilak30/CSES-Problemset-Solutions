#include <bits/stdc++.h>
using namespace std;
 
const long int N = 200002;
vector<long int> v[N];
vector<bool> visited (N,false);
vector<long int> par(N,-1);


long int findBoss(long int empno, long int level){
    while(1){
         if(empno==-1) return -1;
         if(level==0) return empno;
         if(level--){
              empno=par[empno];
         }
    }
}
 
int main() {
	// your code goes here
	long int n,q,x,y;  cin>>n>>q;
	for(long int i=2;i<=n;i++){
	    cin>>x;
	    par[i]=x;
	}
	while(q--){
	     cin>>x>>y;
	     cout<<findBoss(x,y)<<endl;
	}
	
	return 0;
}