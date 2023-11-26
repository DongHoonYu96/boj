#include <bits/stdc++.h>
using namespace std;

int l, c, visited[16];
vector<char> v;
int mo[128];

//현재까지 k번인덱스까지 포함,미포함 판단함 / 모음갯수/ tempStr
void dfs(int k, int cnt, string s) {
	if (k == c) { //리프노드까지 모두탐색함
		if (s.size() == l && cnt >= 1 &&  l - cnt >= 2) {
			cout << s << "\n";
		}
		return;
	}

	//k번째 문자를 포함하는경우
	dfs(k + 1, cnt+mo[v[k]], s + v[k]);
	//포함안하는경우
	dfs(k+1, cnt, s);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> c;
	mo['a'] = 1, mo['e'] = 1, mo['i'] = 1, mo['o'] = 1,mo['u']=1;
	for (int i = 0; i < c; ++i) {
		char c;
		cin >> c;
		v.push_back(c);
		//a.push_back(i);
	}
	sort(v.begin(), v.end());

	dfs(0, 0, "");

	return 0;
}