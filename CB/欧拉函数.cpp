#include <iostream>
#include <cmath>
using namespace std;

int Eular(int n)
{
    int ret = 1;
    for(int i=2; i * i <= n; i++) {
        if(n % i == 0) {
            n /= i;
            ret = ret * (i - 1);
            while(n % i == 0) n/=i,ret*=i;
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

int f(int n)
{
    int ret = n;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
    }

}

int main()
{
    int n,s;
    scanf("%d",&n);
    s=Eular(n);
      printf("%d",s);
      return 0;
}
