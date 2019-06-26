#include <bits/stdc++.h>
using namespace std;

struct Time {
    int year, month, day, hour, minute, second;
    void read() {
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    }
}st, se;

bool Check(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Cal(Time &date)
{
    int cnt = 0;
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i = 1; i < date.month; i++) {
        cnt += month[i]*24*60*60;
    }
    if (Check(date.year) && date.month > 2) cnt += 24*60*60; // 闰年2月多一天
    cnt += (date.day - 1)*24*60*60;
    cnt += date.hour*60*60;
    cnt += date.minute*60;
    cnt += date.second;
    int Jun[11] = {1972,1981,1982,1983,1985,1992,1993,1994,1997,2012,2015};
    if (date.month > 6) {
        for (int i = 0; i < 11; i++) {
            if (Jun[i] == date.year) cnt++;
        }
    }
    return cnt;
}

int main()
{
    st.read(), se.read();
    int Jun[11] = {1972,1981,1982,1983,1985,1992,1993,1994,1997,2012,2015};
    int Dec[16] = {1972,1973,1974,1975,1976,1977,1978,1979,1987,1989,1990,1995,1998,2005,2008,2016};
    int ans = 0;
    for (int i = st.year; i < se.year; i++) {
        if (Check(i)) ans += 366*24*60*60;
        else ans += 365*24*60*60;
        for (int j = 0; j < 11; j++) {
            if (Jun[j] == i) ans++;
        }
        for (int j = 0; j < 16; j++) {
            if (Dec[j] == i) ans++;
        }
    }
    ans -= Cal(st);
    ans += Cal(se);
    cout << ans << endl;
    return 0;
}
