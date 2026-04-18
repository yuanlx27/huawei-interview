#include <bits/stdc++.h>
using namespace std;

class Sudoku {
	array<int, 81> data;
public:
	int& operator [] (int i) {
		return data[i];
	}

	bool avail(int k, int v) {
		int x = k / 9, y = k % 9;
		array<bool, 10> have {};
		for (int i = 0; i < 9; ++i) {
			have[data[x * 9 + i]] = true;
			have[data[i * 9 + y]] = true;
		}
		return !have[v];
	}

	bool check() {
		for (int i = 0; i < 9; ++i) {
			array<int, 10> count {};
			for (int j = 0; j < 9; ++j) {
				++count[data[i * 9 + j]];
			}
			for (int j = 1; j < 10; ++j) {
				if (count[j] != 1) {
					return false;
				}
			}
		}

		for (int i = 0; i < 9; ++i) {
			array<int, 10> count {};
			for (int j = 0; j < 9; ++j) {
				++count[data[j * 9 + i]];
			}
			for (int j = 1; j < 10; ++j) {
				if (count[j] != 1) {
					return false;
				}
			}
		}

		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				array<int, 10> count{};
				for (int x = 0; x < 3; ++x) {
					for (int y = 0; y < 3; ++y) {
						++count[data[(i + x) * 9 + j + y]];
					}
				}
				for (int k = 1; k < 10; ++k) {
					if (count[k] != 1) {
						return false;
					}
				}
			}
		}

		return true;
	}

	void print() {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << data[i * 9 + j] << ' ';
			}
			cout << endl;
		}
	}
} a;

void DFS(int k) {
	if (k >= 81) {
		if (a.check()) {
			a.print();
			exit(0);
		}
		return;
	}

	if (a[k]) {
		DFS(k + 1);
		return;
	}

	for (int i = 1; i < 10; ++i) {
		if (a.avail(k, i)) {
			a[k] = i;
			DFS(k + 1);
			a[k] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> a[i * 9 + j];
		}
	}

	DFS(0);

	return 0;
}