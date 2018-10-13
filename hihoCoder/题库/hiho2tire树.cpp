#include <bits/stdc++.h>
using namespace std;

struct node {
    int cnt;
    node* next[26];
    node()
    {
        cnt = 0;
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }
} trie;

void Create_Trie(string str)
{
    node* p = &trie;
    for(int i = 0; i < str.size(); i++) {
        int c = str[i] - 'a';
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
        int c = str[i] - 'a';
        if(p->next[c] == NULL) return 0;
        p = p->next[c];
    }
    return p->cnt;
}

int main()
{
    int n, q;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        Create_Trie(str);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> str;
        cout << Search_Trie(str) << endl;
    }
    return 0;
}
