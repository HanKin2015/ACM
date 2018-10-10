#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

int cmp(int n) {
    int cnt = 0;
    while(n) {
        if(n % 2) cnt++;
        n /= 2;
    }
    return cnt;
}

int main()
{
    int x;
    while(cin >> x) {
        for(int i = 0; i <= 23; i++) {
            for(int j = 0; j <= 59; j++) {
                if(cmp(i) + cmp(j) == x) {
                    printf("%.2d:%.2d\n", i, j);
                }
            }
        }
    }
    return 0;
}
