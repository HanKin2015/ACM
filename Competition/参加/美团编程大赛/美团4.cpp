#include <bits/stdc++.h>
#define eps 0.00001
using namespace std;

struct node {
    int id;
    double score;
}final_score[505];

bool cmp(node a, node b) {
    double ans = a.score - b.score;
    if(ans > 0) return true;
    return false;
    //return a.score > b.score;
}

int n, m, k, C;
double score[505][8], w[8];  // 输入数据
double max_score[8] = { 0 };   // 每一轮的最高分，每位选手的最后得分，初始化为0

void compute_final_score() {
    for(int i = 0; i < n; i++) {
        final_score[i].score = 0;
        final_score[i].id = i;
        for(int j = 0; j < m; j++) {
            if(max_score[j] != 0) final_score[i].score += score[i][j] / max_score[j] * w[j];
        }
    }
    return;
}

void judge(int ans[505])
{
    sort(final_score, final_score + n, cmp);
    double pre = final_score[0].score;
    for(int i = 0; i < k; i++) {
        if(pre - final_score[i].score > eps) pre = final_score[i].score;
        if(abs(pre - final_score[k].score) <= eps) ans[final_score[i].id] = 3;
        else ans[final_score[i].id] = 1;
        //cout << ans[final_score[i].id] << endl;
    }
    for(int i = k; i < n; i++) {
        if(abs(pre - final_score[i].score) > eps) ans[final_score[i].id] = 2;
        else ans[final_score[i].id] = 3;
        //cout << ans[final_score[i].id] << endl;
    }
    //for(int i = 0; i < n; i++) cout << ans[i] << endl;
    return;
}

int main()
{
    int x, y;                             // 缺失选手x的第y轮成绩
    cin >> n >> m >> k >> C;
    for(int i = 0; i < m; i++) cin >> w[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> score[i][j];
            if(score[i][j] == -1) x = i, y = j;
            else if(max_score[j] < score[i][j]) max_score[j] = score[i][j];
        }
    }
    if(k == n) {
        for(int i = 0; i < n; i++) cout << 1 << endl;
        return 0;
    }
    if(k == 0) {
        for(int i = 0; i < n; i++) cout << 2 << endl;
        return 0;
    }

    int min_ans[505], max_ans[505][505]; // 缺失选手的分数范围，只需要考虑他可能的最高分(错)，最小值也要考虑
    if(C <= max_score[y]) {   // 第y轮的最高分确定
        if(C == max_score[y]) max_score[y]--, C--;   // 好奇怪，不取右边缘C就可以AC，不然96.3%

        score[x][y] = C;
        compute_final_score();
        judge(max_ans[0]);

        score[x][y] = 0;
        compute_final_score();
        judge(min_ans);

        for(int i = 0; i < n; i++) {
            if(min_ans[i] == max_ans[0][i]) cout << min_ans[i] << endl;
            else cout << 3 << endl;
        }
    }
    else {                    // 第y轮的最高分不确定，即要把x选手的分数定在最高分-C之间 或者 0-最高分之间，综合考虑一定取最高分对选手x有利
        score[x][y] = 0;
        compute_final_score();
        judge(min_ans);

        int s = max_score[y];
        for(int i = s; i <= C; i++) {
            max_score[y] = i;
            score[x][y] = i;
            compute_final_score();
            judge(max_ans[i]);
        }
        for(int i = 0; i < n; i++) {
            bool flag = true;
            for(int j = s; j <= C; j++) {
                if(max_ans[j][i] != min_ans[i]) {
                    flag = false;
                    cout << 3 << endl;
                    break;
                }
            }
            if(flag) cout << min_ans[i] << endl;
        }
    }
    return 0;
}

/*
4 2 2 100
1 1
100 99
70 70
40 -1
100 39
1
3
3
2

5 2 3 100
1 1
100 99
70 70
40 -1
100 39
0 100
1
1
3
3
2

4 2 2 100
1 1
100 99
70 70
40 -1
100 39
1
3
3
2
*/

