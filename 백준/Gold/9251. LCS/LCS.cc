#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int d[1004][1004]; 
//LCS(i,j) : x1,x2..xi / y1...yj 의 문자열에서 최대부분문자열의 길이

/*
* 1. 부분문제로 만들기
* 2. 뒤부터 탐색
* 3. 맨뒤가 같은경우 : LCS(i,j)=LCS(i-1,j-1) +1
* 맨뒤를 제외한 LCS에서 +1(같으면 무조건 포함하는게 이득임)을 하면됨.
* 4. 맨뒤가 다른경우 : LCS(i,j) = max(LCS(i-1,j), LCS(i,j-1))
* yj를 제거한 LCS , xi를 제거한 LCS 중 큰값 (끝 문자를 포함을 안하는 경우중 큰거)
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s1 >> s2;
	/*
	* 초기값 표
	* LCS(0, j) = 0 (공집합과 부분문자열은 당연히 0)
	* LCS(i, 0) = 0
	* 전역변수 -> 자동초기화
	*/

	for (int i = 1; i <= s1.size(); ++i) {
		for (int j = 1; j <= s2.size(); ++j) {
			if (s1[i-1] == s2[j-1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[s1.size()][s2.size()];

	return 0;
}