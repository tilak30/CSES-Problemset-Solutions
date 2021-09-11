#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long n,x;  cin>>n;
	set<int> s;
	for(long long i=0;i<n;i++) {
	     cin>>x;
	     s.insert(x);
	}
	cout<<s.size();
	return 0;
}
