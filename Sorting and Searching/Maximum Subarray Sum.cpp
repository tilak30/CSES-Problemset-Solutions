#include <bits/stdc++.h>
using namespace std;

long long maxSubarray(vector<long long> v, long long n){
     long long maxsofar = v[0], maxtillhere = v[0];
     for(int i=1;i<n;i++){
          maxtillhere = max(v[i], v[i]+maxtillhere);
          maxsofar = max(maxsofar, maxtillhere);
     }
     return maxsofar;
}


int main() {
	// your code goes here
	long long n;  cin>>n;
	vector<long long> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<maxSubarray(v,n);
	return 0;
}
