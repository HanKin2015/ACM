#include <iostream>
#include <cmath>
using namespace std;

//计算有n位，其中0占k位时的总的个数
long long int Num_of_com(int n, int k)

{

    double max_num = 1 ;
    for ( int i = 0 ; i < k ; i ++)

    {
        max_num *= ((double)n - i) / (k - i) ; //即n*(n-1)*...*(n-k+1)/k!
    }
    return floor(max_num + 0.0002); //floor(x)返回小于x的最大整数，是C++标准库cmath中的函数，原型只定义了double型。

}

int main(int argc, char **argv)
{
    int m, n, k ;        //0的个数、1的个数、第K个数

    cin >> m >> n >> k;
    long long int biggest = 1 ;
    char *ch = new char[m + n + 1];
    int ch_count = 0;     //字符下标
    ch[m + n] = '\0';        //字符串结束标志

    biggest = Num_of_com(m + n, m) ;

//判断是否有第K个数
    if ( biggest < k  ) {
        cout << -1 << endl;
        return 0;
    }

    int i, j;
    for ( i = 1, j = 0; i <= m && j < n ; ) {
// 假设从最高位为0
        biggest = Num_of_com(m - i + n - j, m - i) ;
        if ( biggest > k  ) {
            ch[ch_count++] = 'a';    //剩余位的组合数总数比K大，说明最高位为0
            i ++;
        } else if ( biggest < k ) {
            ch[ch_count++] = 'z';
            k -= biggest;
            j ++;
        } else if ( biggest == k ) {
            ch[ch_count++] = 'a';   //当前位为0，接下来是所有剩余的1
            while ( j < n ) {
                ch[ch_count++] = 'z';
                j ++;
            }
            while ( i < m ) {   //把剩余的0添加进去
                ch[ch_count++] = 'a';
                i ++;
            }
        }
    }

//补满字符数组的剩余位
    while ( ch_count < m + n )

    {
        ch[ch_count++] = 'a';
        i ++;
    }

    cout << ch << endl;

    return 0;
}
