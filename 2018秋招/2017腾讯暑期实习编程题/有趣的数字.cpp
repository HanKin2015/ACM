#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <climits>
#define LL long long
#define maxn 100005
using namespace std;

int main()
{
    int n, arr[maxn];
    while(cin >> n) {
        map<int, int> cnt;
        set<int> num;
        num.clear();
        cnt.clear();
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            num.insert(arr[i]);   //ȥ�ؼ�����
            //if(find(num.begin(), num.end(), arr[i]) == num.end()) cnt[arr[i]] = 1;
            //else cnt[arr[i]]++;
            cnt[arr[i]]++;        //ÿ����������
        }
        if(n == 1) {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        LL ans1 = 0;   //��Сֵ�Ķ���
        int minn = INT_MAX, pre = *(num.begin());
        for(set<int>::iterator it = ++num.begin(); it != num.end(); it++) {
            int temp = *it - pre;
            if(temp < minn) {
                ans1 = cnt[pre] * cnt[*it];
                minn = temp;
            }
            else if(temp == minn) {
                ans1 += cnt[pre] * cnt[*it];
            }
            pre = *it;
        }
        LL ans2 = cnt[*(num.begin())] * cnt[*(--num.end())];  //���ֵ�Ķ���
        if(cnt[arr[0]] == n) {
            ans2 = n * (n - 1) / 2;
            ans1 = ans2;   //ȫ��һ���Ļ���set�����ֻ��һ����
        }
        LL ans = 0;
        for(int i : num) {  //�ۣ���ǰ�뵽�ˣ�������СֵΪ0���������ǰ����û�м����ȫ��һ����ʱ��ans1
            if(cnt[i] > 1) {    //��ǰ����Ҳ���ˣ�i��ֵ�������±�
                ans += cnt[i] * (cnt[i] - 1) / 2;
            }
        }
        if(ans) {
            cout << ans << ' ';
        }
        else cout<< ans1 << ' ';
        cout << ans2 << endl;
        num.clear();
        cnt.clear();
    }
	return 0;
}
