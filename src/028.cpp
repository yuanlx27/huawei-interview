// https://www.nowcoder.com/practice/b9eae162e02f4f928eac37d7699b352e

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(static_cast<mt19937_64::result_type>(time(nullptr)));

inline bool is_prime(const int &x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

class BipartiteGraph {
	int n;
	vector<bool> vst;
	vector<int> a, ma, mb;
	vector<vector<int>> e;
public:
	BipartiteGraph(int n): n(n), vst(n), a(n), ma(n, -1), mb(n, -1), e(n) {}

	int& operator [] (const int &i) {
		return a[i];
	}

	void add_edge(int u, int v) {
		e[u].emplace_back(v);
	}

	bool search(int u) {
		vst[u] = true;
		for (int v : e[u]) {
			if (mb[v] == -1) {
				ma[u] = v;
				mb[v] = u;
				return true;
			}
		}
		for (int v : e[u]) {
			if (!vst[mb[v]] && search(mb[v])) {
				ma[u] = v;
				mb[v] = u;
				return true;
			}
		}
		return false;
	}

	int match() {
		while (true) {
			bool flag = false;
			vst.assign(n, false);
			for (int i = 0; i < n; ++i) {
				flag |= (ma[i] == -1) && search(i);
			}
			if (!flag) break;
		}

		int foo = 0, bar = 0;
		for (int i = 0; i < n; ++i) {
			if (ma[i] != -1) {
				++foo;
			} else if (a[i] == 1) {
				++bar;
			}
		}
		return foo + bar / 2;
	}
};

int main() {
	int n;
	cin >> n;

	BipartiteGraph g(n);
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[i] % 2 == 1 && g[j] % 2 == 0 && is_prime(g[i] + g[j])) {
				g.add_edge(i, j);
			}
		}
	}

	cout << g.match() << endl;

	return 0;
}