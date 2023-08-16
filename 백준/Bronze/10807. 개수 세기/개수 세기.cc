#include<bits/stdc++.h>
using namespace std;

int n,v,visited[204];
vector<int> vec;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp = 0;
		cin >> temp;
		temp += 100;
		visited[temp]++;
	}
	cin >> v;

	cout << visited[v+100];



}