//��gcc-4.7.2�±���ͨ����
//�����У�g++-Wall-ansi-O2test.cpp-otest
#include <iostream>
using namespace std;
void input(int&oper,const bool meth)
{
//methΪtrue��ֻ�ж�1��Ϊfalse���ж�1��0
    while(true)
    {
        cin>>oper;
        if(meth&&oper==1)
            break;
        else if(oper==0||oper==1)
            break;
        cout<<"����������������롣"<<endl;//�жϲ���
        cin.sync();//���⼫�����뵼����ѭ��
        cin.clear();
    }
}
int main(void)
{
    cout<<"1+1=2����Ҫ������ô�����ˣ���Ҫ�����һ�ѧϰ��"<<endl;
    int ladd,radd,aprs,rcnt(0),wcnt(0);//����������������ȷ������������
    cout<<"��ʼѧϰ����"<<endl;
    for(int i(0); i!=10; ++i)
    {
        cout<<"����1��������1����"<<flush;//��ʾ�������
        input(ladd,true);
        cout<<"����2��������1����"<<flush;
        input(radd,true);
        cout<<"�����"<<(ladd+radd)<<endl;//������
        cout<<"��������������������1������������0����"<<flush;//���۵ȼ�
        input(aprs,false);
        if(aprs)//�ж��û�����
            ++rcnt;
        else
            ++wcnt;
        cout<<"��ȷ������"<<rcnt<<"���������"<<wcnt<<endl;//�������
    }
    if(rcnt>wcnt)//�ж�ѧϰ���
        cout<<"���˸�����1+1=2��"<<endl;
    else if(rcnt<wcnt)
        cout<<"���˸�����1+1!=2��"<<endl;
    else
        cout<<"�Ҳ�����������ʲô��˼��"<<endl;
    int term;//�˳�����
    cout<<"�����ҵı�������������������1������������0��"<<flush;
    input(term,false);
    if(term)
        cout<<"лл�һ����Ŭ��ѧϰ"<<endl;
    else
        cout<<"лл�һ����Ŭ��ѧϰD"<<endl;
//cin>>term;//��Windows�ϲ���ʱ����
    return 0;
}
