#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int T = 5;
    double S = 0;
    while(T--) {
        int t = 100000, sum = 0;
        for(int j = 0; j < t; j++){
            int num[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
            bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
            int cnt = 0;
            while(!(flag1 && flag2)) {
                for(int i = 0; i < 10; i++) {
                    int index = rand() % 10;
                    int temp = num[i];
                    num[i] = num[index];
                    num[index] = temp;
                }
                int i = rand() % 10;
                if(num[i] == 1) flag1 = true;
                if(num[i] == 2) flag2 = true;
                //if(num[i] == 3) flag3 = true;
                //if(num[i] == 4) flag4 = true;
                //if(num[i] == 5) flag5 = true;
                cnt++;
            }
            //cout << cnt << endl;
            sum += cnt;
        }
        double ans = sum * 1.0/ t;
        cout << ans << endl;
        S += ans;
    }
    cout << S / 5 << endl;
}
