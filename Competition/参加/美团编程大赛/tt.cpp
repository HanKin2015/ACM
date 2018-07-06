#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
/*
int CityPos[10][2]= {{87,7},{91,38},{83,46},{71,44},{64,60},{68,58},{83,69},
    {87,76},{74,78},{71,71}
};        //10�����е�����*/
unsigned seed=(unsigned)time(0);//ԭ�ͣ�void srand(unsigned seed);
//30�����е�����

int CityPos[30][2]={{87,7},{91,38},{83,46},{71,44},{64,60},{68,58},{83,69},{87,76},{74,78},{71,71},{58,69},{54,62},{51,67},{37,84},{41,94},{2,99},{7,64},{22,60},{25,62},{18,54},{4,50},{13,40},{18,40},{24,42},{25,38},{41,26},{45,21},{44,35},{58,35},{62,32}};

#define CITY_NUM 30  //��������
#define ANT_NUM 30   //��Ⱥ����
#define TMAC 1000   //����������
#define ROU 0.5     //����С
#define ALPHA 1     // ��Ϣ����Ҫ�̶ȵĲ���
#define BETA 4     // ����ʽ������Ҫ�̶ȵĲ���
#define Q 100 //��Ϣ�ز�������
const int maxn = 100;
double dis[maxn][maxn];        //����
double info[maxn][maxn];  //��Ϣ�ؾ���
double E[CITY_NUM][CITY_NUM]; //�������Ӿ���
int vis[CITY_NUM][CITY_NUM];
double Bestlength;
double ans[CITY_NUM];
const double mmax = 10e9;

//����ָ����Χ�ڵ��������
int rnd(int nLow,int nUpper)
{
    return nLow+(nUpper-nLow)*rand()/(RAND_MAX+1);
}

//����ָ����Χ�ڵ����������
double rnd(double dbLow,double dbUpper)
{
    double dbTemp=rand()/((double)RAND_MAX+1.0);
    return dbLow+dbTemp*(dbUpper-dbLow);
}
//���ظ�������������ȡ����ĸ�����
double ROUND(double dbA)
{
    return (double)((int)(dbA+0.5));
}

struct Ant
{

    int Path[CITY_NUM];  //�����ߵ�·��
    double length;  //·���ܳ���
    int vis[CITY_NUM]; //�߹����б��
    int cur_cityno;   //��ǰ����
    int moved_cnt;    //���ߵ�����
    //��ʼ��
    void Init()
    {
        memset(vis, 0, sizeof(vis));
        length = 0;
        cur_cityno = rnd(0, CITY_NUM);//���ѡ��һ����������
        Path[0] = cur_cityno;
        vis[cur_cityno] = 1;
        moved_cnt = 1;
        //printf("Init %d \n", cur_cityno);
    }
    //ѡ����һ������
    //����ֵ Ϊ���б��
    int chooseNextCity()
    {
        int nSelectedCity=-1; //���ؽ��������ʱ��������Ϊ-1
        //���㵱ǰ���к�ûȥ���ĳ���֮�����Ϣ���ܺ�
        double dbTotal=0.0;
        double prob[CITY_NUM]; //����������б�ѡ�еĸ���
        for(int i = 0; i < CITY_NUM; i++)
        {
            if (!vis[i])
            {
                prob[i]=pow(info[cur_cityno][i],ALPHA)
                        *pow(1.0/dis[cur_cityno][i], BETA);
                dbTotal += prob[i];
            }
            else
            {
                prob[i] = 0;
            }
        }
        //��������ѡ��
        double dbTemp=0.0;
        if (dbTotal > 0.0) //�ܵ���Ϣ��ֵ����0
        {
            dbTemp = rnd(0.0, dbTotal);
            for (int i = 0; i < CITY_NUM; i++)
            {
                if (!vis[i])
                {
                    dbTemp -= prob[i];
                    if (dbTemp < 0.0)
                    {
                        nSelectedCity = i;
                        break;
                    }
                }
            }
        }
        //������м����Ϣ�طǳ�С ( С����double�ܹ���ʾ����С�����ֻ�ҪС )
        //��������������Ͱѵ�һ��ûȥ���ĳ�����Ϊ���ؽ��

        if (nSelectedCity == -1)
        {
            for (int i=0; i<CITY_NUM; i++)
            {
                if (!vis[i]) //����ûȥ��
                {
                    nSelectedCity=i;
                    break;
                }
            }
        }
        return nSelectedCity;
    }

    //�����ڳ��м��ƶ�
    void Move()
    {
        int nCityno = chooseNextCity();//ѡ����һ������
        Path[moved_cnt] = nCityno;//���������ߵ�·��
        vis[nCityno] = 1;//������������ó��Ѿ�ȥ��
        cur_cityno = nCityno;
        //��������·������
        length += dis[Path[moved_cnt-1]][Path[moved_cnt]];
        moved_cnt++;

    }
    //���Ͻ�������һ��
    void Search()
    {
        Init();
        //�������ȥ���ĳ�������С�ڳ����������ͼ����ƶ�
        while(moved_cnt < CITY_NUM)
        {
            Move();
        }
        length += dis[Path[CITY_NUM-1]][Path[0]];
    }

};


struct TSP
{
    Ant ants[ANT_NUM];  //����һȺ����
    Ant ant_best;       //������ý��������

    void Init()
    {
        //��ʼ��Ϊ���ֵ
        ant_best.length = mmax;
        puts("cal dis");
        //�����������м����
        for (int i = 0; i < CITY_NUM; i++)
        {
            for (int j = 0; j < CITY_NUM; j++)
            {
                double temp1=CityPos[j][0]-CityPos[i][0];
                double temp2=CityPos[j][1]-CityPos[i][1];
                dis[i][j] = sqrt(temp1*temp1+temp2*temp2);
            }
        }
        //��ʼ��������Ϣ��
        puts("init info");
        for (int i=0; i<CITY_NUM; i++)
        {
            for (int j=0; j<CITY_NUM; j++)
            {
                info[i][j]=1.0;
            }
        }
    }
    //������Ϣ��,��ǰÿ��·�ϵ���Ϣ�ص��ڹ�ȥ��������Ϣ��
    //����ÿ����������߹�ȥʣ�µ���Ϣ��
    void Updateinfo()
    {
        //puts("update info");
        double tmpinfo[CITY_NUM][CITY_NUM];
        memset(tmpinfo, 0, sizeof(tmpinfo));
        int m = 0;
        int n = 0;
        //����ÿֻ����
        for (int i = 0; i < ANT_NUM; i++) {
            //puts("****");
//            for  (int j = 0; j < CITY_NUM; j++) {
//                printf("%d ", ants[i].Path[j]);
//            }
            //puts("");
            for (int j = 1; j < CITY_NUM; j++)
            {
                m = ants[i].Path[j];
                n = ants[i].Path[j-1];
                //printf("%d %d\n", m, n);
                tmpinfo[n][m] = tmpinfo[n][m]+Q/ants[i].length;
                tmpinfo[m][n] = tmpinfo[n][m];
            }
            //�����кͿ�ʼ����֮�����Ϣ��
            n = ants[i].Path[0];
            tmpinfo[n][m] = tmpinfo[n][m]+Q/ants[i].length;
            tmpinfo[m][n] = tmpinfo[n][m];
        }

         //���»�����Ϣ��
         for (int i = 0; i < CITY_NUM; i++)
         {
             for (int j = 0; j < CITY_NUM; j++) {
                //���µĻ�����Ϣ�� = �������Ϣ�� + �����µ���Ϣ��
                info[i][j] = info[i][j]*ROU + tmpinfo[i][j];

             }
         }
    }
    //Ѱ��·��������TMAC��
    void Search()
    {

        for (int i = 0; i < TMAC; i++) {
            printf("current iteration times %d\n", i);
            for (int j = 0; j < ANT_NUM; j++) {
                ants[j].Search();
            }
            //������ѽ��
            for (int j = 0; j < ANT_NUM; j++) {
                if (ant_best.length > ants[j].length) {
                    ant_best = ants[j];
                }
            }

            //���»�����Ϣ��
            Updateinfo();

            printf("current minimum length %lf\n", ant_best.length);
        }
    }

};



int main()
{
    //freopen("output.txt", "w", stdout);
    srand(seed);
    TSP tsp;
    //��ʼ����Ⱥ
    tsp.Init();
    //��ʼ����
    tsp.Search();
    puts("The Minimum length route is :\n");
    for (int i = 0; i < CITY_NUM; i++) {
        if (i != 0 && i % 20 == 0) {
            puts("");
        }
        printf("%d ", tsp.ant_best.Path[i]);
    }

    return 0;
}
