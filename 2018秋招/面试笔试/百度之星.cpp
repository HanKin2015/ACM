#include <iostream>
#include <cmath>
using namespace std;

//������nλ������0ռkλʱ���ܵĸ���
long long int Num_of_com(int n, int k)

{

    double max_num = 1 ;
    for ( int i = 0 ; i < k ; i ++)

    {
        max_num *= ((double)n - i) / (k - i) ; //��n*(n-1)*...*(n-k+1)/k!
    }
    return floor(max_num + 0.0002); //floor(x)����С��x�������������C++��׼��cmath�еĺ�����ԭ��ֻ������double�͡�

}

int main(int argc, char **argv)
{
    int m, n, k ;        //0�ĸ�����1�ĸ�������K����

    cin >> m >> n >> k;
    long long int biggest = 1 ;
    char *ch = new char[m + n + 1];
    int ch_count = 0;     //�ַ��±�
    ch[m + n] = '\0';        //�ַ���������־

    biggest = Num_of_com(m + n, m) ;

//�ж��Ƿ��е�K����
    if ( biggest < k  ) {
        cout << -1 << endl;
        return 0;
    }

    int i, j;
    for ( i = 1, j = 0; i <= m && j < n ; ) {
// ��������λΪ0
        biggest = Num_of_com(m - i + n - j, m - i) ;
        if ( biggest > k  ) {
            ch[ch_count++] = 'a';    //ʣ��λ�������������K��˵�����λΪ0
            i ++;
        } else if ( biggest < k ) {
            ch[ch_count++] = 'z';
            k -= biggest;
            j ++;
        } else if ( biggest == k ) {
            ch[ch_count++] = 'a';   //��ǰλΪ0��������������ʣ���1
            while ( j < n ) {
                ch[ch_count++] = 'z';
                j ++;
            }
            while ( i < m ) {   //��ʣ���0��ӽ�ȥ
                ch[ch_count++] = 'a';
                i ++;
            }
        }
    }

//�����ַ������ʣ��λ
    while ( ch_count < m + n )

    {
        ch[ch_count++] = 'a';
        i ++;
    }

    cout << ch << endl;

    return 0;
}
