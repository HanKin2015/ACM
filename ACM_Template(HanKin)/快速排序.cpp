#include <bits/stdc++.h>
using namespace std;

/*
//��������
public static void QuickSort(int[] a, int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        QuickSort(a, left, p - 1);
        QuickSort(a, p + 1, right);
    }
}

//�����������黮��
private static int partition(int[] a, int left, int right) {
    int x = a[right];
    int p = left - 1;
    for (int i = left; i < right; i++) {
        if (a[i] <= x) {
            p++;
            swap(a, p, i);
        }
    }
    swap(a, p+1, right);
    return p+1;
}
*/

//��������
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ��������
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
        quick_sort(s, i + 1, r);
    }
    return;
}

//�����������
void rquick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        srand(time(0));
        swap(s[l], s[rand() % (r - l + 1) + l]); //�������������͵�һ������������Ԫ��
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
        quick_sort(s, i + 1, r);
    }
}

int rselect(int A[], int low, int high, int k)
{
    srand(time(0));
    int v = rand() % (high - low + 1) + low - 1;
    int x = A[v];
    vector<int> A1, A2, A3;
    for(int i = low - 1; i < high; i++)
    {
        if(A[i] < x) A1.push_back(A[i]);
        else if(A[i] == x) A2.push_back(A[i]);
        else A3.push_back(A[i]);
    }
    if(A1.size() >= k)
    {
        int arr[105];
        for(int i = 0; i < A1.size(); i++) arr[i] = A1[i];
        return rselect(arr, 1, A1.size(), k);
    }
    else if(A1.size() + A2.size() >= k) return x;
    int arr[105];
    for(int i = 0; i < A3.size(); i++) arr[i] = A3[i];
    return rselect(arr, 1, A3.size(), k - A1.size() - A2.size());
}

//ϲ���İ汾
void Qsort(int a[], int low, int high)
{
    if(low >= high) return;
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/

    while(first < last) {
        while(first < last && a[last] >= key) --last;
        a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/

        while(first < last && a[first] <= key) ++first;
        a[last] = a[first];
        /*���ȵ�һ������Ƶ��߶�*/
    }
    a[first] = key;/*�����¼��λ*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main()
{
    int arr[] = {12, 5, 13, 1, 4};

    int ans = rselect(arr, 1, 5, 3);
    cout << ans << endl;

    rquick_sort(arr, 0, 4);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
