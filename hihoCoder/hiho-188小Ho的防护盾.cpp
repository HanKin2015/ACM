#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, K, A[100005];
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    int L = 0, R = M, ans = -1;
    while(L <= R) { //二分这里老是搞不懂要不要等号，现在明白了，举例子一直往一边取值，必须等号才能取到边缘值
        int mid = (L + R) / 2;
        int cnt = K, value = M;
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(A[i] >= value) { //如果当前的炮弹的伤害大于等于护盾，护盾破坏
                cnt--;
                value = M;
            }
            else{   //否则护盾受到伤害并回血
                value = value - A[i] + mid;
                if(value > M) value = M;
            }
            if(cnt == 0) {  //没有护盾了
                flag = false;
                break;
            }
        }
        if(flag) {  //护盾还存在，间隔值过大
            R = mid - 1;
            ans = mid;
        }
        else L = mid + 1;   //一定要记得加减1
    }
    if(ans == 0) cout << 1 << endl;
    else if(ans != -1) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
