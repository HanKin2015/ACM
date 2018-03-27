#include <bits/stdc++.h>
using namespace std;

int N, M, L, A[1005], LEFT = INT_MAX, RIGHT = INT_MIN;
bool Check(int mid)
{
    for(int i = 0; i < N; i++) { //ö�����
        int times = 0; //�޲�����
        for(int j = i; j < i + N; j++) { //����һȦľͰ���㵱ǰmid��Ҫ�����޲�����
            if(A[j % N] < mid) {
                times++;
                j = j + L - 1; //��ΪС��mid�����Ա����޲�����L��Χ���޲���-1����ΪforҪ+1
            }
        }
        if(times <= M) return true;
    }
    return false;
}

int main()
{
    cin >> N >> M >> L;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        LEFT = min(LEFT, A[i]);
        RIGHT = max(RIGHT, A[i]);
    }
    while(LEFT <= RIGHT) {
        int mid = (LEFT + RIGHT) / 2;
        if(Check(mid)) LEFT = mid + 1;
        else RIGHT = mid - 1;
    }
    cout << RIGHT << endl;
    return 0;
}
