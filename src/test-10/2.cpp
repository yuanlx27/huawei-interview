#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, a, b, x, y;
	cin >> n >> k >> a >> b >> x >> y;

	vector<int> x_dist(n);
	for (int i = 1; i < n; ++i) {
		x_dist[i] = (x_dist[i - 1] + x) % n;
	}
	vector<int> x_step(n, 1e9);
	for (int i = 0; i < n; ++i) {
		x_step[x_dist[i]] = min(x_step[x_dist[i]], i);
	}

	vector<int> y_dist(n);
	for (int i = 1; i < n; ++i) {
		y_dist[i] = (y_dist[i - 1] + n - y) % n;
	}
	vector<int> y_step(n, 1e9);
	for (int i = 0; i < n; ++i) {
		y_step[y_dist[i]] = min(y_step[y_dist[i]], i);
	}

	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, x_step[i] + y_step[(b - a + n - i + n) % n]);
	}
	if (k >= 1) {
		for (int i = 0; i < n; ++i) {
			ans = min(ans, x_step[i] + y_step[(b - a + n + n / 2 - i + n) % n] + 1);
		}
	}
	cout << (ans < 1e9 ? ans : -1) << endl;

	return 0;
}