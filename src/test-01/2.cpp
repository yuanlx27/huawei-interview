#include <bits/stdc++.h>
using namespace std;

inline bool check(const int &s, const int &t) {
	return (t & s) == 0 &&
		   (t & (s << 1)) == 0 &&
		   (t & (s >> 1)) == 0 &&
		   (t & (t << 1)) == 0;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> b(n, vector<int>(1 << m));
        for (int i = 0; i < n; ++i) {
            for (int s = 0; s < (1 << m); ++s) {
                for (int j = 0; j < m; ++j) {
                    if ((s >> j) & 1) {
                        b[i][s] += a[i][j];
                    }
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(1 << m));
        for (int s = 0; s < (1 << m); ++s) {
            if (check(0, s)) {
                dp[0][s] = b[0][s];
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int s = 0; s < (1 << m); ++s) {
                for (int t = 0; t < (1 << m); ++t) {
                    if (check(s, t)) {
                        dp[i][t] = max(dp[i][t], dp[i - 1][s] + b[i][t]);
                    }
                }
            }
        }

        int ans = 0;
        for (int s = 0; s < (1 << m); ++s) {
            ans = max(ans, dp[n - 1][s]);
        }
        cout << ans << endl;
    }

    return 0;
}