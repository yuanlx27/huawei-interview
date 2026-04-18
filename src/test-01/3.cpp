#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int64_t> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(begin(a), end(a));

	int64_t ans = 1e18;
	for (int i = 0; i + m <= n; ++i) {
		ans = min(ans, a[i + m - 1] * a[i + m - 1] - a[i] * a[i]);
	}
	cout << ans << endl;

	return 0;
}