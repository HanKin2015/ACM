/*
���ֵ�ԭ��1�������ͷ��ڴ棨Ұָ�롢�ڴ�й©����2��д���ͷ��ڴ���䣬����֮ǰ���������û��ִ�е���
https://blog.csdn.net/zhuziyu1157817544/article/details/64927834
https://www.cnblogs.com/xiehongfeng100/p/4645555.html
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int* arr = new int[5];   // ����5���ռ�
    int* brr = new int(5);   // ����1���ռ䣬�洢ֵΪ5
    arr[3] = 5;
    brr[3] = 5;
    cout << sizeof(arr) << endl;
    cout << sizeof(brr) << endl;
    int crr[5];
    cout << sizeof(crr) << endl;
    crr[10] = 10;
    cout << crr[10] << endl;
    cout << sizeof(crr) << endl;

    // new�ڷ����ڴ�ʧ��ʱ���׳��쳣������new(std::nothrow)���ڷ����ڴ�ʧ��ʱ�᷵��һ����ָ��
    int *ptr = new(nothrow) int(0);
    if (!ptr) {
        cout << "error" << endl;
        return 0;
    }

    delete ptr;
    ptr = nullptr;
    return 0;
}


#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
    SmartPtr(T *p);
    ~SmartPtr();
    SmartPtr(const SmartPtr<T> &orig);                // ǳ����
    SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // ǳ����
private:
    T *ptr;
    // ��use_count������ָ����Ϊ�˷������ĵ�����ݼ�����
    int *use_count;
};

template<class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p)
{
    try
    {
        use_count = new int(1);
    }
    catch (...)
    {
        delete ptr;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Allocate memory for use_count fails." << endl;
        exit(1);
    }

    cout << "Constructor is called!" << endl;
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    // ֻ�����һ����������ptrʱ���ͷ��ڴ�
    if (--(*use_count) == 0)
    {
        delete ptr;
        delete use_count;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Destructor is called!" << endl;
    }
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig)
{
    ptr = orig.ptr;
    use_count = orig.use_count;
    ++(*use_count);
    cout << "Copy constructor is called!" << endl;
}

// ���صȺź�����ͬ�ڸ��ƹ��캯�������Ⱥ���ߵĶ�������Ѿ�ָ��ĳ���ڴ档
// ���������Ǿ͵����ж���߶���ָ����ڴ��Ѿ������õĴ������������Ϊ1��
// �������ǿ����ͷ�����ڴ棻��֮���ͷţ��������������ͷš�
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
    // ��C++ primer�����������ֵ�������ڼ������������ʹ�ü���֮ǰʹrhs��ʹ�ü�����1��
    // �Ӷ���ֹ����ֵ�������µ������ͷ��ڴ�
    ++(*rhs.use_count);

    // ��������������ʹ�ü�����1�����ö����ʹ�ü�������0����ɾ���ö���
    if (--(*use_count) == 0)
    {
        delete ptr;
        delete use_count;
        cout << "Left side object is deleted!" << endl;
    }

    ptr = rhs.ptr;
    use_count = rhs.use_count;

    cout << "Assignment operator overloaded is called!" << endl;
    return *this;
}
