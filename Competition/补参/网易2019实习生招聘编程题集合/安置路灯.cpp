/*
*��զû�뵽��򵥵�������������.��ʱ��������ƶ�3����λ
*/

#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n, ans = 0, temp = 0; //temp��¼ǰ���ж��ٸ�λ����Ҫ����
        char broad[1005];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> broad[i];
        }
        for(int i = 0; i < n; i++) {
            if(broad[i] == '.') temp++;
            if(temp == 3) {
                ans++;
                temp = 0;
            }
            if(broad[i] == 'X' && temp == 2) {
                ans++;
                temp = 0;
            }
            if(broad[i] == 'X' && temp == 1) {
                ans++;
                temp = 0;
                i++;
            }
        }
        if(temp) ans++;
        cout << ans << endl;
    }
    return 0;
}
