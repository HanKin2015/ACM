#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, K, A[100005];
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    int L = 0, R = M, ans = -1;
    while(L <= R) { //�����������Ǹ㲻��Ҫ��Ҫ�Ⱥţ����������ˣ�������һֱ��һ��ȡֵ������ȺŲ���ȡ����Եֵ
        int mid = (L + R) / 2;
        int cnt = K, value = M;
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(A[i] >= value) { //�����ǰ���ڵ����˺����ڵ��ڻ��ܣ������ƻ�
                cnt--;
                value = M;
            }
            else{   //���򻤶��ܵ��˺�����Ѫ
                value = value - A[i] + mid;
                if(value > M) value = M;
            }
            if(cnt == 0) {  //û�л�����
                flag = false;
                break;
            }
        }
        if(flag) {  //���ܻ����ڣ����ֵ����
            R = mid - 1;
            ans = mid;
        }
        else L = mid + 1;   //һ��Ҫ�ǵüӼ�1
    }
    if(ans == 0) cout << 1 << endl;
    else if(ans != -1) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
