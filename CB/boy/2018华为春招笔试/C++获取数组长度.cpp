#include<iostream>
using namespace std;

template<class T>  //����������ʱ�����ݵ���ָ�룬��������ģ����
int length(T& arr)
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

int main()
{
    int arr[] = { 1,5,9,10,9,2 };
    // ����һ
    cout << "����ĳ���Ϊ��" << length(arr) << endl;
    // ������
    //cout << end(arr) << endl;
    //cout << begin(arr) << endl;
    cout << "����ĳ���Ϊ��" << end(arr)-begin(arr) << endl;
    system("pause");
    return 0;
}
