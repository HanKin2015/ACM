#include <bits/stdc++.h>
using namespace std;

char* DeleteSpace(char* str)
{
    char* p = str, *q = str;
    int len = strlen(str);
    while (*q != '\0') {  // ָ���ַ���û��"\0"����char������
        if (*q != ' ') {
            *p = *q;
            p++;
        }
        q++;
    }
    *p = '\0';
    return str;
}

#include <functional>
void PQueue()
{
    priority_queue<int, vector<int>, greater<int> > Q;   // ����Ԫ�ش�С�����˳�����
    //priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> countMax;

    int A[] = {7, 5, 2, 1, 3, 4, 6};
    for (int i = 0; i < 7; i++) {
        Q.push(A[i]);
        int tmp = Q.top();
        cout << tmp << endl;
    }
    return;
}

int fun(int n)
{
    return n;
}

int main()
{
    assert(fun(5) == 6);

    int a[] = {2, 5, 6, 8, 3, 1, 4};
    sort(a, a + 7, greater<int>());    // �����ݼ�(�����greaterȱһ����)
    for (int i = 0; i < 7; i++) cout << a[i] << ' ';
    cout << endl;
    sort(a, a + 7, less<int>());       // ��������
    for (int i = 0; i < 7; i++) cout << a[i] << ' ';
    cout << endl;

    //assert(DeleteSpace("  he jian  ") == "hejian");
    //char* str = "  he jian  ";   // ����д��ָ���ַ�����ָ�벻�ܶ���ֵ�����޸�
    char str[] = "  he jian  ";
    cout << DeleteSpace(str) << endl;

    PQueue();
    return 0;
}
