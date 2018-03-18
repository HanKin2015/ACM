#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s = "";
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') s += "%20";
            else s += str[i];
        }
        strcpy(str, s.c_str());
	}
};

int main()
{
    Solution HanKin;
    HanKin.replaceSpace("We Are Happy", 12);
    return 0;
}
