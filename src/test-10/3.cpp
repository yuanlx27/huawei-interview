#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector<vector<int64_t>> dp(m + 1, vector<int64_t>(2, 1e18));
	dp[0][0] = dp[0][1] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = m; j >= 0; --j) {
			dp[min(j + x[i], m)][0] = min(dp[min(j + x[i], m)][0], dp[j][0] + y[i]);
			dp[min(j + x[i], m)][1] = min(dp[min(j + x[i], m)][1], dp[j][1] + y[i]);
			dp[min(j + x[i] * 2, m)][1] = min(dp[min(j + x[i] * 2, m)][1], dp[j][0] + y[i] / 2);
		}
	}

	cout << min(dp[m][0], dp[m][1]) << endl;

	return 0;
}