# 1.������ֻ����һ�ε�һ������
# 2.������ֻ����һ�ε���������
# 3.�����Ķ����Ʊ�ʾ
ԭ��ȡ���ɷ��룬Ȼ���һ�ɲ���

# 4.������������������
# 5.�����������������˻�������������











����C++������ж��ļ���Ŀ¼���ڵ����ɷ���

���ȹ����ж��ļ��Ĵ����ԣ�

һ��ifstream

��C++�У���������ifstream�ļ���������������ֱ��ʹ��ifstream�������ļ���������ʱ������ļ���������������ʧ�ܡ�

ifstream fin("hello.txt");
if (!fin)
{
   std::cout << "can not open this file" << endl;
����c++����õķ�ʽ��

 

����File

C��Ҳ��ͬ���������ǿ���File����ز�����

File* fh = fopen("hello","r");
if(fh == NULL)
{
   printf("%s","can not open the file");
}
 

����_access

��ȻC�л���һ�ַ�ʽ��ֱ�ӵ���c�ĺ����⡣

���Ǻ��� int _access(const char* path,int mode);

��������Ĺ���ʮ��ǿ��

���Կ���msdn����ϸ����

���ƴ���
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


# ���������ʾʹ�ò��������͵�ʱ�򣬼ǵò鿴�ǲ��������˶�Ӧ��ͷ�ļ�

1.vector���ǲ����ͷ��ڴ�



ɾ������������Ԫ��ʱ��������ʹ���еĿռ䱻�ͷţ���ʱ����ʹ����������ﵽ�ͷŶ���ռ��Ŀ�ģ� s ��ʾĿ��������T��ʾ������Ԫ�����ͣ���

vector<T>(s.begin(), s.end(), swap(s));

�������� s �����ݴ���һ����ʱ���������������ٽ��������� s ��������ʱ s ԭ��ռ�еĿռ��Ѿ�������ʱ���󣬸����ִ����ɺ���ʱ����ᱻ�������ռ䱻�ͷš�

 

2.deque��ʱ���ͷ��ڴ�



deque���ڴ����鲻�ٱ�ʹ��ʱ���ᱻ�ͷš�deque���ڴ��С�ǿ������ġ��������ǲ�����ô���Լ���ô����ʵ�ʰ汾���塣

 

3.list,set,multiset,map,multimap���ǻ��ͷ��ڴ�



listһ��ʵ��Ϊһ��˫��������set��multiset��map��multimapһ��ʵ��Ϊһ��ƽ�����������������Ԫ�ر�ɾ��ʱ��Ԫ����ռ���ڴ汻�ͷš�