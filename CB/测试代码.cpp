#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int sum;
int prime(int s)
{

        for(int i=1;i<=(int)sqrt(s);i++)
        if(s%i==0)
        {
            if(i*i!=s)
                sum+=2;
            else
                sum++;
        }
        return sum;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        scanf("%d",&p);
        p--;
        sum=0;
        printf("%d\n",prime(p));
    }
    return 0;
}
