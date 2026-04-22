#include <bits/stdc++.h>
using namespace std;

inline int lowbit(const int &x) {
	return x & -x;
}

int main() {
	int n, C, M;
	cin >> n >> C >> M;

	vector<int> c(1 << n), m(1 << n), v(1 << n);
	for (int i = 0; i < n; ++i) {
		cin >> c[1 << i] >> m[1 << i] >> v[1 << i];
	}
	for (int s = 0; s < (1 << n); ++s) {
		c[s] = c[s ^ lowbit(s)] + c[lowbit(s)];
		m[s] = m[s ^ lowbit(s)] + m[lowbit(s)];
		v[s] = v[s ^ lowbit(s)] + v[lowbit(s)];
	}

	vector<vector<int>> dp(n + 1, vector<int>(1 << n));
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int s = 0; s < (1 << n); ++s) {
			for (int t = s; t; t = (t - 1) & s) {
				if (c[t] <= C && m[t] <= M) {
					dp[i][s] = max(dp[i][s], dp[i - 1][s ^ t] + v[t]);
				}
			}
			ans = max(ans, dp[i][s]);
		}
		cout << ans << endl;
	}

	return 0;
}