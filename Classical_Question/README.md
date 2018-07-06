# 1.数组中只出现一次的一个数字
# 2.数组中只出现一次的两个数字
# 3.负数的二进制表示
原码取反成反码，然后加一成补码

# 4.求任意三个数的最大和
# 5.求任意三个数的最大乘积，包含正负零











关于C++中如何判断文件，目录存在的若干方法

首先关于判断文件的存在性：

一、ifstream

在C++中，可以利用ifstream文件输入流，当我们直接使用ifstream来创建文件输入流的时候，如果文件不存在则流创建失败。

ifstream fin("hello.txt");
if (!fin)
{
   std::cout << "can not open this file" << endl;
这是c++中最常用的方式。

 

二、File

C中也是同样道理，我们可是File的相关操作。

File* fh = fopen("hello","r");
if(fh == NULL)
{
   printf("%s","can not open the file");
}
 

三、_access

当然C中还有一种方式是直接调用c的函数库。

就是函数 int _access(const char* path,int mode);

这个函数的功能十分强大。

可以看看msdn的详细介绍

复制代码
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
int main( void )
{
    // Check for existence.
    if( (_access( "crt_ACCESS.C", 0 )) != -1 )
    {
        printf_s( "File crt_ACCESS.C exists.\n" );
        // Check for write permission.
        // Assume file is read-only.
        if( (_access( "crt_ACCESS.C", 2 )) == -1 )
            printf_s( "File crt_ACCESS.C does not have write permission.\n" );
    }
}


# 如果出现提示使用不完整类型的时候，记得查看是不是引用了对应的头文件

1.vector总是不会释放内存



删除向量容器的元素时，并不会使空闲的空间被释放，这时可以使用下面的语句达到释放多余空间的目的（ s 表示目的容器，T表示容器的元素类型）：

vector<T>(s.begin(), s.end(), swap(s));

即首先用 s 的内容创建一个临时的向量容器对象，再将该容器和 s 交换，这时 s 原先占有的空间已经属于临时对象，该语句执行完成后临时对象会被析构，空间被释放。

 

2.deque有时会释放内存



deque的内存区块不再被使用时，会被释放。deque的内存大小是可缩减的。不过，是不是这么做以及怎么做由实际版本定义。

 

3.list,set,multiset,map,multimap总是会释放内存



list一般实现为一个双向链表，而set、multiset、map、multimap一般实现为一个平衡二叉树。当容器中元素被删除时，元素所占的内存被释放。