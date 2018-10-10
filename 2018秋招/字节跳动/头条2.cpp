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
        cout << str[i];
        if (p->cnt == 1) break;
    }
    return 0;
}

int main()
{
    int n, q;
    cin >> n;
    string str[1005];
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        Create_Trie(str[i]);
    }
    for(int i = 0; i < n; i++) {
        Search_Trie(str[i]);
        cout << endl;
    }
    return 0;
}
/*
5
bytedance
toutiaohao
toutiaoapp
iesaweme
iestiktok
*/

/*
python±©Á¦Ò²ÐÐ???

def string_index(n, s_lst):
    res = []
    for s in s_lst:
        copy_lst = s_lst.copy()
        copy_lst.remove(s)
        for i in range(1, len(s)):
            temp = s[:i]
            count = 0
            for l in copy_lst:
                if temp != l[:i]:
                    count += 1
            if count == n - 1:
                res.append(temp)
                break
    return res

if __name__ == "__main__":
    n = int(input())
    s_lst = []
    for i in range(n):
        s_lst.append(input())
    res = string_index(n, s_lst)
    for s in res:
        print(s)
*/

