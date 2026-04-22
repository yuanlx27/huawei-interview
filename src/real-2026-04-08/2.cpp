#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	auto delta = [&](int idx) -> int {
		return a[idx] - max((a[idx] + 1) / 2, b[idx]);
	};
	

	for (int i = 0; i < m; ++i) {
		int k = 0;
		for (int j = 0; j < n; ++j) {
			if (delta(j) > delta(k)) {
				k = j;
			}
		}
		a[k] = max((a[k] + 1) / 2, b[k]);
	}

	cout << accumulate(begin(a), end(a), 0) << endl;

	return 0;
}