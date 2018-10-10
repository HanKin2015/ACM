#include <iostream>
#include <cstring>
#include <map>
using namespace std;

struct {
    char token1[15];
    bool flag1;  //true is alpha, false is digit.
    char token2[15];
    bool flag2;
    bool op;     //true is <, false is <=.
}binaryPair[1005], binaryPair2[1005];
map<char, int> var;

int CharToDigit(char ch[15])
{
    int ans = 0;
    for(int i = 0; i < strlen(ch); i++) {
        ans = (int)(ch[i] - '0') + ans * 10;
    }
    return ans;
}

void judge(int dex)
{
    for(int i = 0; i < dex; i++) {
        int A, B;
        if(binaryPair[i].flag1) A = var[binaryPair[i].token1[0]];
        else A = CharToDigit(binaryPair[i].token1);
        if(binaryPair[i].flag2) B = var[binaryPair[i].token2[0]];
        else B = CharToDigit(binaryPair[i].token2);
        if(binaryPair[i].op) {
            if(A >= B) {
//                cout << A << ' ' << B;
                cout << "No" << endl;
                return ;
            }
        }
        else {
            if(A > B) {
//                cout << A << ' ' << B;
                cout << "No" << endl;
                return ;
            }
        }
    }
    cout << "Yes" << endl;
    return ;
}

int main()
{
//    char cha[] = "12423";
//    cout << CharToDigit(cha) << endl;
    char format[1005];
    int N, T, dex = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> format;
        char ch[15];
        int tag = 0;
        for(int j = 0; j < strlen(format); j++) {
            ch[tag++] = format[j];
            if(format[j + 1] == '<') {
                j++;
                if(format[j + 1] == '=') {
                    binaryPair[dex].op = false;
                    j++;
                }
                else binaryPair[dex].op = true;
                if(tag == 1 && ch[0] >= 'A' && ch[0] <= 'Z') binaryPair[dex].flag1 = true;
                else binaryPair[dex].flag1 = false;
                strcpy(binaryPair[dex].token1, ch);
                int k = j + 1;
                if(k == strlen(format)) break;
                tag = 0;
                while(k < strlen(format) && format[k] != '<') {
                    ch[tag++] = format[k++];
                }
                if(tag == 1 && ch[0] >= 'A' && ch[0] <= 'Z') binaryPair[dex].flag2 = true;
                else binaryPair[dex].flag2 = false;
                strcpy(binaryPair[dex].token2, ch);
                tag = 0;
                dex++;
            }
        }
    }

    for(int i = 0; i < dex; i++) {
        binaryPair2[i] = binaryPair[i];
//        cout << binaryPair[i].token1 << " ";
//        cout << binaryPair[i].flag1 << " ";
//        cout << binaryPair[i].token2 << " ";
//        cout << binaryPair[i].flag2 << " ";
//        cout << binaryPair[i].op << endl;
    }

    cin >> T;

    char ch;
    int num, cnt = 0, all = -3;
    bool flag = true;
    for(int i = 0; i < T; i++) {
        while(!flag) {
            if(cnt == all) {
                cnt = 0;
                judge(dex);
                var.clear();
                break;
            }
            cin >> ch;
            cin >> num;
            var[ch] = num;
            cnt++;
        }
        while(flag) {
            cin >> ch;
            cin >> num;
            if(var.find(ch) != var.end()) {
                judge(dex);
                var.clear();
                var[ch] = num;
                flag = false;
                all = cnt;
                cnt = 1;
                break;
            }
            var[ch] = num;
//            cout << var[ch] << endl;
            cnt++;
        }
    }
    return 0;
}
