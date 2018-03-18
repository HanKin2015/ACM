#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

struct node{
    int w, s, c;
    int over;
};

bool cmp1(node a, node b) {
    return a.s < b.s;
}

bool cmp2(node a, node b) {
    if(a.over == b.over) return a.w < b.w;
    return a.over < b.over;
}

int main()
{
    int N, K, loc[1005];
    node temp[1005], tmp[1005];
    cin >> N >> K;
    for(int i = 1; i <= N; i++) loc[i] = i;
    for(int i = 0; i < K; i++) {
        cin >> temp[i].w >> temp[i].s >> temp[i].c;
        temp[i].over = temp[i].s + temp[i].c;
        tmp[i] = temp[i];
    }
    sort(temp, temp + K, cmp1);
    sort(tmp, tmp + K, cmp2);
    set<int> space;
    int dex1 = 0, dex2 = 0;  //loc[Ô¿³×±àºÅ] = Î»ÖÃ±àºÅ
    while(dex1 < K || dex2 < K) {
        if(dex1 == K) {
            while(dex2 < K) {
                int locate = *space.begin();
                space.erase(locate);
                loc[tmp[dex2].w] = locate;
                dex2++;
            }
        }
        else {
            if(temp[dex1].s < tmp[dex2].over) {
                space.insert(loc[temp[dex1].w]);
                dex1++;
            }
            else if(temp[dex1].s >= tmp[dex2].over) {
                int locate = *space.begin();
                space.erase(locate);
                loc[tmp[dex2].w] = locate;
                dex2++;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(loc[j] == i) {
                cout << j << ' ';
                break;
            }
        }
    }
    return 0;
}
