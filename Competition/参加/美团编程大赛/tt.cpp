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
};        //10个城市的坐标*/
unsigned seed=(unsigned)time(0);//原型：void srand(unsigned seed);
//30个城市的坐标

int CityPos[30][2]={{87,7},{91,38},{83,46},{71,44},{64,60},{68,58},{83,69},{87,76},{74,78},{71,71},{58,69},{54,62},{51,67},{37,84},{41,94},{2,99},{7,64},{22,60},{25,62},{18,54},{4,50},{13,40},{18,40},{24,42},{25,38},{41,26},{45,21},{44,35},{58,35},{62,32}};

#define CITY_NUM 30  //城市数量
#define ANT_NUM 30   //蚁群数量
#define TMAC 1000   //迭代最大次数
#define ROU 0.5     //误差大小
#define ALPHA 1     // 信息素重要程度的参数
#define BETA 4     // 启发式因子重要程度的参数
#define Q 100 //信息素残留参数
const int maxn = 100;
double dis[maxn][maxn];        //距离
double info[maxn][maxn];  //信息素矩阵
double E[CITY_NUM][CITY_NUM]; //启发因子矩阵
int vis[CITY_NUM][CITY_NUM];
double Bestlength;
double ans[CITY_NUM];
const double mmax = 10e9;

//返回指定范围内的随机整数
int rnd(int nLow,int nUpper)
{
    return nLow+(nUpper-nLow)*rand()/(RAND_MAX+1);
}

//返回指定范围内的随机浮点数
double rnd(double dbLow,double dbUpper)
{
    double dbTemp=rand()/((double)RAND_MAX+1.0);
    return dbLow+dbTemp*(dbUpper-dbLow);
}
//返回浮点数四舍五入取整后的浮点数
double ROUND(double dbA)
{
    return (double)((int)(dbA+0.5));
}

struct Ant
{

    int Path[CITY_NUM];  //蚂蚁走的路径
    double length;  //路径总长度
    int vis[CITY_NUM]; //走过城市标记
    int cur_cityno;   //当前城市
    int moved_cnt;    //已走的数量
    //初始化
    void Init()
    {
        memset(vis, 0, sizeof(vis));
        length = 0;
        cur_cityno = rnd(0, CITY_NUM);//随机选择一个出发城市
        Path[0] = cur_cityno;
        vis[cur_cityno] = 1;
        moved_cnt = 1;
        //printf("Init %d \n", cur_cityno);
    }
    //选择下一个城市
    //返回值 为城市编号
    int chooseNextCity()
    {
        int nSelectedCity=-1; //返回结果，先暂时把其设置为-1
        //计算当前城市和没去过的城市之间的信息素总和
        double dbTotal=0.0;
        double prob[CITY_NUM]; //保存各个城市被选中的概率
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
        //进行轮盘选择
        double dbTemp=0.0;
        if (dbTotal > 0.0) //总的信息素值大于0
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
        //如果城市间的信息素非常小 ( 小到比double能够表示的最小的数字还要小 )
        //出现这种情况，就把第一个没去过的城市作为返回结果

        if (nSelectedCity == -1)
        {
            for (int i=0; i<CITY_NUM; i++)
            {
                if (!vis[i]) //城市没去过
                {
                    nSelectedCity=i;
                    break;
                }
            }
        }
        return nSelectedCity;
    }

    //蚂蚁在城市间移动
    void Move()
    {
        int nCityno = chooseNextCity();//选择下一个城市
        Path[moved_cnt] = nCityno;//保存蚂蚁走的路径
        vis[nCityno] = 1;//把这个城市设置成已经去过
        cur_cityno = nCityno;
        //更新已走路径长度
        length += dis[Path[moved_cnt-1]][Path[moved_cnt]];
        moved_cnt++;

    }
    //蚂蚁进行搜索一次
    void Search()
    {
        Init();
        //如果蚂蚁去过的城市数量小于城市数量，就继续移动
        while(moved_cnt < CITY_NUM)
        {
            Move();
        }
        length += dis[Path[CITY_NUM-1]][Path[0]];
    }

};


struct TSP
{
    Ant ants[ANT_NUM];  //定义一群蚂蚁
    Ant ant_best;       //保存最好结果的蚂蚁

    void Init()
    {
        //初始化为最大值
        ant_best.length = mmax;
        puts("cal dis");
        //计算两两城市间距离
        for (int i = 0; i < CITY_NUM; i++)
        {
            for (int j = 0; j < CITY_NUM; j++)
            {
                double temp1=CityPos[j][0]-CityPos[i][0];
                double temp2=CityPos[j][1]-CityPos[i][1];
                dis[i][j] = sqrt(temp1*temp1+temp2*temp2);
            }
        }
        //初始化环境信息素
        puts("init info");
        for (int i=0; i<CITY_NUM; i++)
        {
            for (int j=0; j<CITY_NUM; j++)
            {
                info[i][j]=1.0;
            }
        }
    }
    //更新信息素,当前每条路上的信息素等于过去保留的信息素
    //加上每个蚂蚁这次走过去剩下的信息素
    void Updateinfo()
    {
        //puts("update info");
        double tmpinfo[CITY_NUM][CITY_NUM];
        memset(tmpinfo, 0, sizeof(tmpinfo));
        int m = 0;
        int n = 0;
        //遍历每只蚂蚁
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
            //最后城市和开始城市之间的信息素
            n = ants[i].Path[0];
            tmpinfo[n][m] = tmpinfo[n][m]+Q/ants[i].length;
            tmpinfo[m][n] = tmpinfo[n][m];
        }

         //更新环境信息素
         for (int i = 0; i < CITY_NUM; i++)
         {
             for (int j = 0; j < CITY_NUM; j++) {
                //最新的环境信息素 = 留存的信息素 + 新留下的信息素
                info[i][j] = info[i][j]*ROU + tmpinfo[i][j];

             }
         }
    }
    //寻找路径，迭代TMAC次
    void Search()
    {

        for (int i = 0; i < TMAC; i++) {
            printf("current iteration times %d\n", i);
            for (int j = 0; j < ANT_NUM; j++) {
                ants[j].Search();
            }
            //保存最佳结果
            for (int j = 0; j < ANT_NUM; j++) {
                if (ant_best.length > ants[j].length) {
                    ant_best = ants[j];
                }
            }

            //更新环境信息素
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
    //初始化蚁群
    tsp.Init();
    //开始查找
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
