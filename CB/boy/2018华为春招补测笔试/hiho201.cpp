#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    char str[100005], str_pair[3];
    map<string, bool> illegal;
    cin >> N;
    cin >> str;
    cin >> M;
    while(M--) {
        cin >> str_pair;
        illegal[str_pair] = 1;
        string temp = "";
        temp += str_pair[1];
        temp += str_pair[0];
        illegal[temp] = 1;
    }

    int dp[100005], pos[26];
    for(int i = 0; i < 26; i++) pos[i] = -1;
    dp[0] = 1;
    pos[str[0] - 'a'] = 0;
    for(int i = 1; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < 26; j++) {
            if(pos[j] != -1) {
                string temp = "";
                temp += str[i];
                temp += str[pos[j]];
                if(illegal[temp] != 1) {
                    dp[i] = max(dp[i], dp[pos[j]] + 1);
                }
                //else dp[i] = max(dp[i], dp[j]);  //这步有问题
                //用dp[i]表示最后留下一个字符是str[i]时，最多留下多少个字符。不留str[i]答案不就是p[i - 1]嘛
                /*基于上一行的分析，所以答案要是dp中的最大值*/
            }
        }
        pos[str[i] - 'a'] = i;   //存储字母最后出现的位置
    }
    //for(int i = 0; i < N; i++) cout << dp[i] << ' ';
    int maxn = *max_element(dp, dp + N);
    cout << N - maxn << endl;
    return 0;
}

/*
4 abcd 3
ab
dc
bc

好奇怪，错在哪里了？先优化
aabb
aaaa

4 abcd 3
ad
bd
cd
答案应该是1
*/



