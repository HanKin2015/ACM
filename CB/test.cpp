#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    cout << "dsad" << endl;
    cout << 0x30 << endl;
    cout << 0x7fffffff << endl;
    cout << 0x3f3f3f3f << endl;
    int dp1[105], dp2[105];
    memset(dp1, 0x30, sizeof(dp1));
    memset(dp2, 48, sizeof(dp2));
    cout << dp1[34] << endl;
    cout << dp2[34] << endl;

    char ch = 'a';
    stringstream stream;
    stream << ch;
    string str = stream.str();
    cout << str << endl;
    return 0;
}
