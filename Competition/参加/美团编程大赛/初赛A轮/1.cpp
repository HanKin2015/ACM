#include <bits/stdc++.h>
using namespace std;

struct node {
  int x, y;
};

int main()
{
    //char - 'A' / 3 + 1 = 1;
    node phone[9];
    int num = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            phone[num].x = i;
            phone[num++].y = j;
        }
    }
    int T; cin >> T;
    while(T--) {
        //string str;
        //cin >> str;
        char str[100005];
        cin >> str;
        int ans = 0;
        int pre_x = 0, pre_y = 0;
        for(int i = 0; i < strlen(str); i++) {
            int loc;
            if(str[i] >= 'W') str[i] = 'W';
            if(str[i] >= 'S' && str[i] <= 'V') loc = int(str[i] - 'B') / 3 + 1;
            else loc = int(str[i] - 'A') / 3 + 1;
            ans = ans + abs(phone[loc].x - pre_x) + abs(phone[loc].y - pre_y);
            pre_x = phone[loc].x;
            pre_y = phone[loc].y;
        }
        cout << ans << endl;
    }
    return 0;
}
