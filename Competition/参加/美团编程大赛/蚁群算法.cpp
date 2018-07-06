#include <bits/stdc++.h>
#define CITY_NUM 30             // ��������
#define ANT_NUM 30              // ��Ⱥ����
#define ITERATOR_MAX_NUM 1000   // ����������
#define eps 0.5                 // ����С
#define ALPHA 1                 // ��Ϣ����Ҫ�̶ȵĲ���
#define BETA 4                  // ����ʽ������Ҫ�̶ȵĲ���
#define Q 100                   //��Ϣ�ز�������
#define maxn 1005
#define LL long long
using namespace std;

int CityPos[maxn][2];           // ���е�����
double dis[maxn][maxn];         // ����
double info[maxn][maxn];        // ��Ϣ�ؾ���
double E[CITY_NUM][CITY_NUM];   // �������Ӿ���
int vis[CITY_NUM][CITY_NUM];
double Bestlength;
double ans[CITY_NUM];
const double mmax = 10e9;

struct Ant {

    int path[CITY_NUM];     // �����ߵ�·��
    LL path_length;         // ·���ܳ���
    bool vis[CITY_NUM];     // �߹����б��
    int cur_city;           // ��ǰ����
    int moved_cnt = 0;      // ���ߵ�����
    // ��ʼ��-----���ѡȡһ��������
    void Init() {
        memset(vis, 0, sizeof(vis));
        path_length = 0;
        cur_city = rand() % CITY_NUM;   // ���ѡ��һ����������
        path[0] = cur_city;
        vis[cur_city] = 1;
        moved_cnt = 1;
        //printf("Init %d \n", cur_city);
    }

    // ѡ����һ������,����ֵΪ���б��
    int Choose_Next_City() {
        int city_id = -1;       //���ؽ��,��ʼ��Ϊ-1
        //���㵱ǰ���к�ûȥ���ĳ���֮�����Ϣ���ܺ�
        double dbTotal = 0.0;
        double prob[CITY_NUM]; //����������б�ѡ�еĸ���
        for(int i = 0; i < CITY_NUM; i++) {
            if (!vis[i]) {
                prob[i] = pow(info[cur_city][i], ALPHA) * pow(1.0 / dis[cur_city][i], BETA);
                dbTotal += prob[i];
            }
            else prob[i] = 0;
        }
        // ��������ѡ��
        double dbTemp = 0.0;
        if (dbTotal > 0.0) {    // �ܵ���Ϣ��ֵ����0
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

        // ������м����Ϣ�طǳ�С ( С����double�ܹ���ʾ����С�����ֻ�ҪС )
        // ��������������Ͱѵ�һ��ûȥ���ĳ�����Ϊ���ؽ��
        if (city_id == -1) {
            for (int i = 0; i < CITY_NUM; i++) {
                if (!vis[i]) { //����ûȥ��
                    city_id = i;
                    break;
                }
            }
        }
        return city_id;
    }

    //�����ڳ��м��ƶ�
    void Move() {
        int next_city = Choose_Next_City();  // ѡ����һ������
        path[moved_cnt] = next_city;         // ���������ߵ�·��
        vis[next_city] = 1;                  // ������������ó��Ѿ�ȥ��
        cur_city = next_city;
        // ��������·������
        path_length += dis[path[moved_cnt - 1]][path[moved_cnt]];
        moved_cnt++;

    }

    // ���Ͻ�������һ��
    void Search() {
        Init();
        // �������ȥ���ĳ�������С�ڳ����������ͼ����ƶ�
        while(moved_cnt < CITY_NUM) Move();
        path_length += dis[path[CITY_NUM - 1]][path[0]];
    }
};


struct TSP {
    Ant ants[ANT_NUM];  // ����һȺ����
    Ant ant_best;       // ������ý��������

    void Init() {
        // ��ʼ��Ϊ���ֵ
        ant_best.path_length = INT_MAX;
        cout << "Compute distance between citys...." << endl;
        // �����������м����
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                double temp1 = CityPos[j][0] - CityPos[i][0];
                double temp2 = CityPos[j][1] - CityPos[i][1];
                dis[i][j] = sqrt(temp1 * temp1 + temp2 * temp2);
            }
        }
        // ��ʼ��������Ϣ��
        cout << "Init environment infomation hormone as 1.0...." << endl;
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                info[i][j] = 1.0;
            }
        }
    }
    // ������Ϣ��,��ǰÿ��·�ϵ���Ϣ�ص��ڹ�ȥ��������Ϣ��
    // ����ÿ����������߹�ȥʣ�µ���Ϣ��
    void Updateinfo() {
        //puts("update info");
        double tmpinfo[CITY_NUM][CITY_NUM];
        memset(tmpinfo, 0, sizeof(tmpinfo));

        // ����ÿֻ����
        for (int i = 0; i < ANT_NUM; i++) {
            int m, n;
            for (int j = 1; j < CITY_NUM; j++) {
                m = ants[i].path[j];       // ��ǰ����
                n = ants[i].path[j - 1];   // ǰһ������
                //printf("%d %d\n", m, n);
                tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].path_length;
                tmpinfo[m][n] = tmpinfo[n][m];
            }
            // �����кͿ�ʼ����֮�����Ϣ��
            n = ants[i].path[0];
            tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].path_length;
            tmpinfo[m][n] = tmpinfo[n][m];
        }

        // ���»�����Ϣ��
        for (int i = 0; i < CITY_NUM; i++) {
            for (int j = 0; j < CITY_NUM; j++) {
                // ���µĻ�����Ϣ�� = �������Ϣ�� + �����µ���Ϣ��
                info[i][j] = info[i][j] * eps + tmpinfo[i][j];
            }
        }
        return;
    }

    // Ѱ��·��������ITERATOR_MAX_NUM��
    void Search() {
        for (int i = 0; i < ITERATOR_MAX_NUM; i++) {
            printf("Current iteration times %d\n", i);
            for (int j = 0; j < ANT_NUM; j++) ants[j].Search();

            //������ѽ��
            for (int j = 0; j < ANT_NUM; j++) {
                if (ant_best.path_length > ants[j].path_length) {
                    ant_best = ants[j];
                }
            }

            //���»�����Ϣ��
            Updateinfo();
            printf("Current minimum length %lf\n", ant_best.path_length);
        }
    }
};

void Load_Tsp_File(char* file_name) {
    cout << "file_name = " << file_name << endl;
    cout << "Load Tsp File...." << endl << endl;
    FILE *fin = fopen(file_name, "r");

    int tex = 0;   // �±�
    while (!feof(fin)) {
        int node = 0;
        char attr[maxn];   //�������׳����ڴ����̫С�����ֶδ���
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
    unsigned seed = (unsigned)time(0);   //ԭ��: void srand(unsigned seed);
    srand(seed);
    TSP tsp;
    tsp.Init();   //��ʼ����Ⱥ
    tsp.Search(); //��ʼ����
    cout << "The Minimum length route is :" << endl;
    for (int i = 0; i < CITY_NUM; i++) {
        cout << tsp.ant_best.path[i] << ' ';
    }
    cout << endl;
    cout << "Mininum length = " << tsp.ant_best.path[CITY_NUM] << endl;
    return 0;
}
