#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		array<int, 26> count {};
		for (char c : s) {
			++count[c - 'a'];
		}

		sort(begin(count), end(count));

		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			ans += count[i] * (i + 1);
		}
		cout << ans << endl;
	}

	return 0;
}