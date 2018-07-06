#include <bits/stdc++.h>
using namespace std;

const int inf = 1<<30;

int main()
{
    //cout << inf << endl;
    int N;
    while(cin >> N) {
        int dp[205][205];
        //vector<vector<int> > f(n + 1, vector<int>(n + 1, 0));  //这样的二维数组附初值
        for(int l = N; l > 0; l--) {
            for(int r = l + 1; r <= N; r++) {
                dp[l][r] = inf;  //当l和r相等的时候初始为无穷大？？？
                for(int k = l; k <= r; k++) {
                    int s = 0;   //B选择哪个区间A付出的代价最大
                    if(k > l) s = max(s, dp[l][k - 1]);  //前面的条件仅仅排除k==l的情况
                    if(k < r) s = max(s, dp[k + 1][r]);
                    dp[l][r] = min(dp[l][r], s + k);  //当前选择k值，则需要付出k的代价
                }
            }
        }
        cout << dp[1][N] << endl;
    }
    return 0;
}

/*
开始的想法(隔两个数取值)是错的，如N=8，答案就是12，而不是16
应该是折半向上取整，并且向大的方向走
然而又WA了，第一次30分，第二次40分。仔细一想贪心寻找规律这种失败
动态规划，A会选择最小的代价选择数字，B会使自己获得最大收益改变数字
dp[l][r]是答案，即A付出的最小代价，B的作用是改变左右摇摆的方向，会选择dp[l][r]最大代价的区间
注意题目中n最大值为200，说明复杂度有可能是n^3，接近1秒
*/
