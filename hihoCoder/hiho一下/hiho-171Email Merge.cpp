#include <bits/stdc++.h>
using namespace std;
//using namespace stdext;
//#include <ext/hash_map>
using namespace __gnu_cxx;
//The include file <ext/hash_map> refers to the GNU extension hash map class and this is declared in namespace __gnu_cxx.

int father[10005];
int FindFather(int x)
{
    if(father[x]!=x)
    father[x] = FindFather(father[x]);
    return father[x];
}

void Union(int x, int y)
{
    int fx = FindFather(x);
    int fy = FindFather(y);
    if(fx > fy) father[fx] = fy;
    else if(fx < fy) father[fy] = fx;
    return;
}

int main()
{
    //hash_map<string, int> username;
    //hash_map<string, int> email;
    //map<string, int> username;
    unordered_map<string, vector<int> > email;
    string username[10005];
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        father[i] = i;
        cin >> username[i];
        //if(username.find(temp) != username.end()) { //put username into integer
        //    username[temp] = i;     //every row input different username
        //}
        int cnt;
        cin >> cnt;
        while(cnt--) {
            string temp;
            cin >> temp;
            for(int j : email[temp]) Union(j, i);  //寻找共同父亲根
            email[temp].push_back(i);
        }
    }
    map<int, vector<int> > path;
    for(int i = 1; i <= N; i++) {
        int fx = FindFather(i);  // 将当前用户名添加到第一次出现的父亲用户名容器里
        path[fx].push_back(i);
    }
    for(map<int, vector<int> >::iterator it = path.begin(); it != path.end(); it++) {
        for(int i : it -> second) {
            cout << username[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
