#include <bits/stdc++.h>

using namespace std;

int N,p,m,g,na,ret1=-1000000000 -1;
int ret2 = 1000000000+1;
vector<int> v;

//n번째자리, 들어갈연산
void dfs(int n, vector<char> a,int P,int M,int G,int NA) {
	if (n == N) {
		int sum = v[0];
		for (int i = 0; i < N-1; ++i) {
			if (a[i] == '+') {
				sum += v[i+1];
			}
			if (a[i] == '-') {
				sum -= v[i + 1];
			}
			if (a[i] == '*') {
				sum *= v[i + 1];
			}
			if (a[i] == '/') {
				sum /= v[i + 1];
			}
			
		}
		ret1 = max(ret1, sum);
		ret2 = min(ret2, sum);
		return;
	}
	if (P > p || M > m || G > g || NA > na) return;

	//+인경우
	a.push_back('+');
	dfs(n + 1, a,P+1,M,G,NA);
	a.pop_back();

	//-인경우
	a.push_back('-');
	dfs(n + 1, a, P , M+1, G, NA);
	a.pop_back();

	//*인경우
	a.push_back('*');
	dfs(n + 1, a, P , M, G+1, NA);
	a.pop_back();

	// /인경우
	a.push_back('/');
	dfs(n + 1, a, P, M, G, NA+1);
	a.pop_back();
}
int main() {
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> p >> m >> g >> na;

	vector<char> v1;
	dfs(0, v1,0,0,0,0);
	cout << ret1<<"\n"<<ret2;
	return 0;
}