#include <bits/stdc++.h>
#define CITY_NUM 30             // 城市数量
#define ANT_NUM 30              // 蚁群数量
#define ITERATOR_MAX_NUM 1000   // 迭代最大次数
#define eps 0.5                 // 误差大小
#define ALPHA 1                 // 信息素重要程度的参数
#define BETA 4                  // 启发式因子重要程度的参数
#define Q 100                   //信息素残留参数
#define maxn 1005
#define LL long long
using namespace std;

int CityPos[maxn][2];           // 城市的坐标
double dis[maxn][maxn];         // 距离
double info[maxn][maxn];        // 信息素矩阵
double E[CITY_NUM][CITY_NUM];   // 启发因子矩阵
int vis[CITY_NUM][CITY_NUM];
double Bestlength;
double ans[CITY_NUM];
const double mmax = 10e9;

struct Ant {

    int path[CITY_NUM];     // 蚂蚁走的路径
    LL path_length;         // 路径总长度
    bool vis[CITY_NUM];     // 走过城市标记
    int cur_city;           // 当前城市
    int moved_cnt = 0;      // 已走的数量
    // 初始化-----随机选取一个起点城市
    void Init() {
        memset(vis, 0, sizeof(vis));
        path_length = 0;
        cur_city = rand() % CITY_NUM;   // 随机选择一个出发城市
        path[0] = cur_city;
        vis[cur_city] = 1;
        moved_cnt = 1;
        //printf("Init %d \n", cur_city);
    }

    // 选择下一个城市,返回值为城市编号
    int Choose_Next_City() {
        int city_id = -1;       //返回结果,初始化为-1
        //计算当前城市和没去过的城市之间的信息素总和
        double dbTotal = 0.0;
        double prob[CITY_NUM]; //保存各个城市被选中的概率
        for(int i = 0; i < CITY_NUM; i++) {
            if (!vis[i]) {
                prob[i] = pow(info[cur_city][i], ALPHA) * pow(1.0 / dis[cur_city][i], BETA);
                dbTotal += prob[i];
            }
            else prob[i] = 0;
        }
        // 进行轮盘选择
        double dbTemp = 0.0;
        if (dbTotal > 0.0) {    // 总的信息素值大于0
            dbTemp = rand() / ((double)RAND_MAX + 1.0) * dbTotal;
            for (int i = 0; i < CITY_NUM; i++) {
                if (!vis[i]) {
                    dbTemp -= prob[i];
                    if (dbTemp < 0.0) {
                        city_id = i;
                        break;
                    }
                }
            }
        }

        // 如果城市间的信息素非常小 ( 小到比double能够表示的最小的数字还要小 )
        // 出现这种情况，就把第一个没去过的城市作为返回结果
        if (city_id == -1) {
            for (int i = 0; i < CITY_NUM; i++) {
                if (!vis[i]) { //城市没去过
                    city_id = i;
                    break;
                }
            }
        }
        return city_id;
    }

    //蚂蚁在城市间移动
    void Move() {
        int next_city = Choose_Next_City();  // 选择下一个城市
        path[moved_cnt] = next_city;         // 保存蚂蚁走的路径
        vis[next_city] = 1;                  // 把这个城市设置成已经去过
        cur_city = next_city;
        // 更新已走路径长度
        path_length += dis[path[moved_cnt - 1]][path[moved_cnt]];
        moved_cnt++;

    }

    // 蚂蚁进行搜索一次
    void Search() {
        Init();
        // 如果蚂蚁去过的城市数量小于城市数量，就继续移动
        while(moved_cnt < CITY_NUM) Move();
        path_length += dis[path[CITY_NUM - 1]][path[0]];
    }
};


struct TSP {
    Ant ants[ANT_NUM];  // 定义一群蚂蚁
    Ant ant_best;       // 保存最好结果的蚂蚁

    void Init() {
        // 初始化为最大值
        ant_best.path_length = INT_MAX;
        cout << "Compute distance between citys...." << endl;
        // 计算两两城市间距离
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                double temp1 = CityPos[j][0] - CityPos[i][0];
                double temp2 = CityPos[j][1] - CityPos[i][1];
                dis[i][j] = sqrt(temp1 * temp1 + temp2 * temp2);
            }
        }
        // 初始化环境信息素
        cout << "Init environment infomation hormone as 1.0...." << endl;
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                info[i][j] = 1.0;
            }
        }
    }
    // 更新信息素,当前每条路上的信息素等于过去保留的信息素
    // 加上每个蚂蚁这次走过去剩下的信息素
    void Updateinfo() {
        //puts("update info");
        double tmpinfo[CITY_NUM][CITY_NUM];
        memset(tmpinfo, 0, sizeof(tmpinfo));

        // 遍历每只蚂蚁
        for (int i = 0; i < ANT_NUM; i++) {
            int m, n;
            for (int j = 1; j < CITY_NUM; j++) {
                m = ants[i].path[j];       // 当前城市
                n = ants[i].path[j - 1];   // 前一个城市
                //printf("%d %d\n", m, n);
                tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].path_length;
                tmpinfo[m][n] = tmpinfo[n][m];
            }
            // 最后城市和开始城市之间的信息素
            n = ants[i].path[0];
            tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].path_length;
            tmpinfo[m][n] = tmpinfo[n][m];
        }

        // 更新环境信息素
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                // 最新的环境信息素 = 留存的信息素 + 新留下的信息素
                info[i][j] = info[i][j] * eps + tmpinfo[i][j];
            }
        }
        return;
    }

    // 寻找路径，迭代ITERATOR_MAX_NUM次
    void Search() {
        for (int i = 0; i < ITERATOR_MAX_NUM; i++) {
            printf("Current iteration times %d\n", i);
            for (int j = 0; j < ANT_NUM; j++) ants[j].Search();

            //保存最佳结果
            for (int j = 0; j < ANT_NUM; j++) {
                if (ant_best.path_length > ants[j].path_length) {
                    ant_best = ants[j];
                }
            }

            //更新环境信息素
            Updateinfo();
            printf("Current minimum length %lf\n", ant_best.path_length);
        }
    }
};

void Load_Tsp_File(char* file_name) {
    cout << "file_name = " << file_name << endl;
    cout << "Load Tsp File...." << endl << endl;
    FILE *fin = fopen(file_name, "r");

    int tex = 0;   // 下标
    while (!feof(fin)) {
        int node = 0;
        char attr[maxn];   //这里容易出现内存分配太小，出现段错误
        //fscanf(fin, "%d\t%s\n", &node, &attr);
        fgets(attr, maxn, fin);
        if(attr == "EOF") break;
        int cnt = -1;
        if(attr[0] >= '0' && attr[0] <= '9') {
            for(int i = 0; i < maxn; i++) {
                if(attr[i] == ' ') {
                    if(cnt == 0) CityPos[tex][0] = node;
                    if(cnt == 1) {
                        CityPos[tex++][1] = node;
                        break;
                    }
                    cnt++;
                    node = 0;
                    continue;
                }
                node += int(attr[i] - '0') * 10;
            }
        }
        for(int i = 0; i < tex; i++) {
            cout << CityPos[i][0] << ' ' << CityPos[i][1] << endl;
        }
    }
    fclose(fin);
    return;
}

int main()
{
    Load_Tsp_File("rand50.tsp"); return 0;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    unsigned seed = (unsigned)time(0);   //原型: void srand(unsigned seed);
    srand(seed);
    TSP tsp;
    tsp.Init();   //初始化蚁群
    tsp.Search(); //开始查找
    cout << "The Minimum length route is :" << endl;
    for (int i = 0; i < CITY_NUM; i++) {
        cout << tsp.ant_best.path[i] << ' ';
    }
    cout << endl;
    cout << "Mininum length = " << tsp.ant_best.path[CITY_NUM] << endl;
    return 0;
}
