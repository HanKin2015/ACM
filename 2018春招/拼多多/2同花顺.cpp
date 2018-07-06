#include <bits/stdc++.h>
using namespace std;

void INSERT(string pork, set<int> &S) {
    if(pork.size() == 3) S.insert(10);
    else if(pork[1] == 'J') S.insert(11);
    else if(pork[1] == 'Q') S.insert(12);
    else if(pork[1] == 'K') S.insert(13);
    else if(pork[1] == 'A') S.insert(14), S.insert(1);
    else S.insert(pork[1] - '0');
    return;
}

bool JUDGE(set<int> S) {
    if(S.size() < 5) return false;
    auto it = S.begin();
    int pre = *it, cnt = 1;
    it++;
    for(; it != S.end(); it++) {
        if(*it == pre + 1) cnt++;
        else cnt = 1;
        pre = *it;
        if(cnt == 5) return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n;
    while(n--) {
        cin >> m;
        string pork;
        set<int> S, H, C, D;
        for(int i = 0; i < m; i++) {
            cin >> pork;
            if(pork[0] == 'S') INSERT(pork, S);
            else if(pork[0] == 'H') INSERT(pork, H);
            else if(pork[0] == 'C') INSERT(pork, C);
            else INSERT(pork, D);
        }
        if(JUDGE(S) || JUDGE(H) || JUDGE(C) || JUDGE(D)) cout << 'Y' << endl;
        else cout << 'N' << endl;
    }
    return 0;
}

/*
3
5 D10 DJ DQ DK DA
10 SA S10 SJ SQ H10 HK H4 HK C2 D7
10 SA S4 S5 S3 H10 HK H4 HK C2 S2
*/
