#include <bits/stdc++.h>

using namespace std;
multiset<int> tickets;

void solve() {
	int n,m,h,t; 
	cin >> n >> m;
	for (int i=0;i<n;++i){
		cin >> h; tickets.insert(h);
	}
	for (int i=0;i<m;++i){
		cin >> t;
		auto it = tickets.upper_bound(t);
		if (it==tickets.begin()){
			cout << -1 << "\n";
		}
		else{
			cout << *(--it) << "\n";
			tickets.erase(it);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}