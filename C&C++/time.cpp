#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main()
{
    string skr = "";
    int t = 9;
    for (int i = 0; i < 5; i++)
        skr += to_string(t) + "_";
    cout << skr << endl;


    cout << R"()" << endl;

/*
tm_sec
分钟后的几秒 (0-59)。
tm_min
小时后的分钟 (0-59)。
tm_hour
午夜后经过的小时 (0-23)。
tm_mday
月 (1-31) 天。
tm_mon
月 (0 – 11;年 1 月 = 0）。
tm_year
年份 （当前年份减去 1900年）。
tm_wday
星期几 (0 – 6;星期日 = 0）。
tm_yday
每年的一天 (0-365;1 月 1 日 = 0)。
tm_isdst
如果夏令时有效，则为，正值夏时制不起作用; 如果为 0如果夏时制的状态是未知的负值。 如果 TZ 设置环境变量，C 运行库会假定规则适用于美国境内用于实现夏令时 (DST) 计算。
*/
    time_t seed = time(NULL);
    struct tm *nowTime = localtime(&seed);
    cout << nowTime->tm_mon << nowTime->tm_mday << endl;
    skr = "";
    skr += to_string(nowTime->tm_mon) + to_string(nowTime->tm_mday);
    cout << skr << endl;



    int a = 10;
    double b = 10;
    //cout << a / 0 << endl;  // ³ÌÐò±ÀÀ£
    cout << b / 0 << endl;    // Êä³öinf
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        flag = !flag;
        cout << flag << endl;
    }
    return 0;
}
