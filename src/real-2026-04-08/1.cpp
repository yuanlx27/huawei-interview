#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s(1, 'a' + (n < 0));
	n = abs(n);

	int b;
	while (cin >> b) {
		s += 'a' + (n % b);
		n /= b;
	}

	string ans;
	for (int len = 0; len < s.length(); ++len) {
		for (int i = 0; i + len < s.length(); ++i) {
			string t = s.substr(i, len + 1);
			if (equal(t.begin(), t.end(), t.rbegin())) {
				if (t.length() > ans.length() || t < ans) {
					ans = t;
				}
			}
		}
	}

	if (ans == s) {
		cout << ans << "(palindrome)" << endl;
	} else {
		cout << ans << endl;
	}

	return 0;
}