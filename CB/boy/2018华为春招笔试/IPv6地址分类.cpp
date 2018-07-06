#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10005
using namespace std;

bool number(char ch) {
    if(ch == 'A' || ch == 'B' || ch == '8' || ch =='9') return true;
    return false;
}

bool check(string ip) {
    int len = ip.size();
    //if(len != 39) return false;
    for(int i = 0; i < len; i++) {
        if(ip[i] < '0' || ip[i] > '9') {
            if(ip[i] < 'A' || ip[i] > 'F') {
                if(ip[i] != ':') return false;
            }
        }
    }
    return true;
}

int main()
{
    string ip;
    while(cin >> ip) {
        if(!check(ip)) {
            cout << "Error" << endl;
            continue;
        }
        if(ip[0] == 'F' && ip[1] == 'E') {
            if(number(ip[2])) {
                cout << "LinkLocal" << endl;
                continue;
            }
            if(ip[2] >= 'C' && ip[2] <= 'F') {
                cout << "SiteLocal" << endl;
                continue;
            }
        }
        bool flag = true;
        int len = ip.size();
        for(int i = 0; i < len - 1; i++) {
            if(ip[i] != ':') {
                if(ip[i] != '0') {
                    flag = false;
                    break;
                }
            }
        }
        if(flag && ip[len - 1] == '1') {
            cout << "Loopback" << endl;
            continue;
        }
        if(flag && ip[len - 1] == '0') {
            cout << "Unspecified" << endl;
            continue;
        }
        if(ip[0] == 'F' && ip[1] == 'F') {
            cout << "Multicast" << endl;
            continue;
        }
        cout << "GlobalUnicast" << endl;
    }
	return 0;
}
