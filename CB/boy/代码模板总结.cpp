#include<bits/stdc++.h>

#define rep(i, l, r) for(int i=l; i<=r; i++)
#define dow(i, l, r) for(int i=l; i>=r; i--)
#define clr(x, c) memset(x, c, sizeof(x))
#define travel(x) for(edge *p=fir[x]; p; p=p->n)
#define all(x) (x).begin,(x).end
#define pb push_back
#define fi first
#define se second
#define l(x) Left[x]
#define r(x) Right[x]
#define lowbit(x) (x&-x)

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef long double ld;
typedef unsigned long long ull;

inline int read()
{
    int x=0; bool f=0; char ch=getchar();
    while (ch<'0' || '9'<ch) f|=ch=='-', ch=getchar();
    while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
    return f?-x:x;
}

#define maxn 109

#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=105;

#include <bits/stdc++.h>
#define db double
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define pii pair <int, int>
#define rep(i, a, b) for (int i = (a), __end = (b); i <= __end; ++i)
#define repdown(i, a, b) for (int i = (a), __end = (b); i >= __end; --i)
#define RG register
#define clr(a) memset(a, 0, sizeof(a))
using namespace std;

const int mod = 998244353;
