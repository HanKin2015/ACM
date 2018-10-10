//质因数的快速求法
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin >> n) {
        //Pollard Rho因数分解，时间复杂度是n^0.25？不是n
        for(int i = 2; i <= n; i++) {
            if(n % i == 0) cout << i << ' ';
            while(n % i == 0) n /= i;
            //if (n == 1) break;  你知道为啥不需要这步吗?你知道为啥复杂度不是n吗?答案在循环条件里n在变化
        }
        cout << endl;
    }
    return 0;
}
