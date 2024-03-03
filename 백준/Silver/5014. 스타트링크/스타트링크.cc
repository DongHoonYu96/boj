#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d,ret=987654321;
int v[1000000 + 4];


int main() {
	cin.tie(0);

	cin >> f>>s>> g>> u>> d;

	queue<int> q;
	q.push(s);
	v[s] = 1; //초기방문체크

	while (q.size()) {
		int cur = q.front(); q.pop();
		for (auto nxt : { cur + u, cur - d }) {
			if (nxt<=0 || nxt>f) continue;
			if (v[nxt]) continue;
			
			q.push(nxt);
			v[nxt] = v[cur] + 1;
		}
	}

	if (v[g] == 0) {
		cout << "use the stairs";
		return 0;
	}
	cout << v[g]-1;

	return 0;
}