#include <bits/stdc++.h>
using namespace std;

struct node {
    int cnt;
    node* next[10];
    node()
    {
        cnt = 0;
        for(int i = 0; i < 10; i++) next[i] = NULL;
    }
} trie;

void Create_Trie(string str)
{
    node* p = &trie;
    for(int i = 0; i < str.size(); i++) {
        int c = str[i] - '0';
        if(p->next[c] == NULL)
            p->next[c] = new node;
        p = p->next[c];
        p->cnt++;
    }
}

int Search_Trie(string str)
{
    node* p = &trie;
    for(int i = 0; i < str.size(); i++) {
        int c = str[i] - '0';
        if(p->next[c] == NULL) return 0;
        p = p->next[c];
    }
    return p->cnt;
}

int main()
{
    int N, M;
    cin >> N >> M;
    string str;
    unordered_map<string, bool> vis;
    for(int i = 0; i < N; i++) {
        cin >> str;
        if (!vis[str]) {
            vis[str] = true;
            Create_Trie(str);
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> str;
        cout << Search_Trie(str) << endl;
    }
    return 0;
}

