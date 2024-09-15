
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lis[1004], lis2[1004], dp1[1004], dp2[1004];
int nums[1004];
int n,len, len2;

int main()
{
    //memset(dp1, 1, sizeof(dp1));
    //memset(dp2, 1, sizeof(dp2));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(lis, lis + len, nums[i]) - lis;

        if (idx == len) {
            len++;
        }
        //(lis에없는)개큰수가 등장한 경우, 맨뒤에 추가해줌, lis길이+1
        //lb 성질에 의해 없는수를 찾으면 v.end()==len를 반환함!!

        lis[idx] = nums[i]; //기존값을 더 작은값으로 교체
        dp1[i] = len;
    }
   /* for (int i = 0; i < n; ++i) {
        cout << dp1[i] << " ";
    }cout << "\n";*/


    for (int i = n-1; i >= 0; --i) {
        int idx = lower_bound(lis2, lis2 + len2, nums[i]) - lis2;

        if (idx == len2) {
            len2++;
        }
        //(lis에없는)개큰수가 등장한 경우, 맨뒤에 추가해줌, lis길이+1
        //lb 성질에 의해 없는수를 찾으면 v.end()==len를 반환함!!

        lis2[idx] = nums[i]; //기존값을 더 작은값으로 교체
        dp2[i] = len2;
    }

    /*for (int i = 0; i < n; ++i) {
        cout << dp2[i] << " ";
    }cout << "\n";*/

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dp1[i] + dp2[i] - 1);
    }

    cout << ret;

    return 0;
}