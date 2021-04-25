#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
bool visit[MAX];
int d[MAX];
int N, R, Q;
int dfs(int x) {
	if (visit[x])
		return d[x];
	visit[x] = true;
	for (auto i : v[x]) {
		if (!visit[i]) {
			d[x] = d[x] + dfs(i);
		}
	}
	return d[x];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;
	fill(d, d + MAX, 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(R);
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << d[q] << "\n";
	}
}
