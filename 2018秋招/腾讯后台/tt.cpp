//�������Ŀ�����
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin >> n) {
        //Pollard Rho�����ֽ⣬ʱ�临�Ӷ���n^0.25������n
        for(int i = 2; i <= n; i++) {
            if(n % i == 0) cout << i << ' ';
            while(n % i == 0) n /= i;
            //if (n == 1) break;  ��֪��Ϊɶ����Ҫ�ⲽ��?��֪��Ϊɶ���ӶȲ���n��?����ѭ��������n�ڱ仯
        }
        cout << endl;
    }
    return 0;
}
