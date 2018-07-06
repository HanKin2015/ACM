/*
*���ֲ���
*���Ҳ����ڲ�ѯֵ�����ֵ��
*/
#include <bits/stdc++.h>
using namespace std;

//�۰���Ҽǵ�Ҫ������
//������Ϊ��������ʱ��ʵ���ϴ��ݵ���һ��ָ�룬����sizeof�ķ�������ȡ������ָ��ĳ��ȡ�
template<class T>  //ģ���̾�����
bool binary_find(T &arr, int n)
{
    int len = sizeof(arr) / sizeof(arr[0]);  //�����ﴫ�ݵ�ʱ����������
    cout << len << endl;
    int l = 0, r = len - 1;
    while(l < r) {
        int mid = (l + r) / 2;cout << arr[mid] << endl;
        if(arr[mid] > n) r = mid - 1;
        else if(arr[mid] < n) l = mid + 1;
        else return true;
    }
    return false;
}

int main()
{
    //int arr[7] = {5, 6, 7, 9, 12, 1, 3 };
    int arr[3] = {1, 10, 100};
    int q = 10;          //���ش�6
    int len = sizeof(arr) / sizeof(int);  //�������鳤�ȵĴ�С
    cout << "�����С = " << len << endl;
    //���ֲ���һ��Ҫ�ǵ�������
    sort(arr, arr + len);
    int l = 0, r = len - 1;   //��һ��ע���r�Ƿ�ȡ�õ�����Ϊl��ȡ������r��ɡ�
    while(l <= r) {      //�����������Ҫ��������ȡ���ڣ�ȡr����ߣ������ģ��һ��
        int mid = (r + l) / 2;
        if(arr[mid] > q) r = mid - 1;  //ע��������Ҫ�Ӽ�
        else if(arr[mid] < q) l = mid + 1;
        else {
            r = mid;    //mid�Ǵ�
            break;
        }
    }
    cout << arr[r] << endl;
    cout << boolalpha << binary_find(arr, 10) << endl;

    /*
    STL�й��ڶ��ֲ��ҵĺ���������lower_bound ��upper_bound ��binary_search ���������������䣨���ֲ��ҵ�ǰ�ᣩ��
    lower_bound�㷨����һ���ǵݼ�����[first, last)�еĵ�һ�����ڵ���ֵval��λ�á�
    upper_bound�㷨����һ���ǵݼ�����[first, last)�еĵ�һ������ֵval��λ�á�
    */
    int a[] = {1, 2, 3, 3, 4, 5, 6, 6, 7};
    auto pos1 = lower_bound(a, a + 9, 3);  //���������Ǹ�����lower_bound�ܿ�������
    cout << pos1 - a << endl;  //aֱ���������һ��Ԫ�صĵ�ַ
    auto pos2 = upper_bound(a, a + 9, 3);
    cout << pos2 - a << endl;  //aֱ���������һ��Ԫ�صĵ�ַ
    auto pos3 = binary_search(a, a + 9, 3);  //������ҷ���ֵΪboolֵ
    cout << pos3 << endl;  //aֱ���������һ��Ԫ�صĵ�ַ
    return 0;
}
