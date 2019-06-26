#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin >> K;
    string S;
    cin >> S;
    set<pair<char, int> > SET;
    int end = S.size() - K;  // 区间末端
    int start = 0;    // 区间始端
    for (int i = start; i <= end; i++) {
        SET.insert(pair<char, int>(S[i], i));
    }
    while (K--) {
        pair<char, int> p = *(SET.begin());
        int pos = p.second;
        cout << p.first;
        for (int i = start; i <= pos; i++) {
            SET.erase(pair<char, int>(S[i], i));
        }
        end++;
        SET.insert(pair<char, int>(S[end], end));
        start = pos + 1;
    }
    cout << endl;
    return 0;
}
