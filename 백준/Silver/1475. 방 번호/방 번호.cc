#include <bits/stdc++.h>
using namespace std;

int v[10];
string s;
int ret;

void print_v()
{
	for (int i = 0; i < 10; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}
int main(){
		
	//1. N 자리수마다 필요한 숫자 세기
	//ex) 9999 -> need[6]=4

	//단 9는 6으로 치환.
	//세트에 9는 없고, 6이 2개잇는것으로 간주
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] - '0' == 9) {
			s[i] = '6';
		}
		v[s[i] - '0']++;
	}
	

	//print_v();

	//need중 최대값 == 필요한 set의수
	//단, need[6]=need[6]/2 해야함
	if (v[6] % 2 == 0) {
		v[6] /= 2;
	}
	else {
		v[6] /= 2;
		v[6]++;
	}
	int max = 0;
	for (int i = 0; i < 10; ++i) {
		if (max < v[i]) max = v[i];
	}
	cout << max;

}