#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define LL long long
#define maxn 10005
using namespace std;

int main()
{
    int N; cin >> N; getchar();  //��ò�Ҫʹ��getchar�����س�����ȡ��
    int direct = 0;  //��-1����+1����0����1����2����3
    for(int i = 0; i < N; i++) {
        if(getchar() == 'L') direct --;
        else direct++;
    }
    //cout << direct << endl;
    direct += 8000;
    switch(direct % 4) {
        case 0: cout << 'N' << endl; break;
        case 1: cout << 'E' << endl; break;
        case 2: cout << 'S' << endl; break;
        case 3: cout << 'W' << endl;
    }
	return 0;
}
