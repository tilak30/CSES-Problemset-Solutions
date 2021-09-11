#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll INF = 1e18;

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> mat(n, vector<ll>(n, INF));

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w, u--, v--;
		if (w < mat[u][v]) mat[u][v] = mat[v][u] = w;
	}

	// floyd-warshall
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (mat[i][k] + mat[k][j] < mat[i][j])
					mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];

	while (q--) {
		int u, v;
		cin >> u >> v, u--, v--;
		if (u == v) mat[u][v] = 0;
		if (mat[u][v] == INF) mat[u][v] = -1;
		cout << mat[u][v] << "\n";
	}
}
