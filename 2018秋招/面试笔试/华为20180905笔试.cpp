#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input1, input2;
    cin >> input1;
    cin >> input2;
    int len1 = input1.size(), len2 = input2.size(), cnt[26] = {0};
    for (int i = 0; i < len1; i++) cnt[input1[i] - 'A']++;
    bool flag = true;
    for (int i = 0; i < len2; i++) {
        if (cnt[input2[i] - 'A'] == 0) {
            flag = false;
            break;
        }
    }
    cout << boolalpha << flag << endl;
    return 0;
}
/*
BBDDCFFEL
LCEFB
*/
