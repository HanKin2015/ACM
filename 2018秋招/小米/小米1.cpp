#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, pattern;
    while (cin >> text >> pattern) {
        int minLen = INT_MAX, START = -1, END = -1;
        int len1 = text.size(), len2 = pattern.size();
        for (int i = 0; i <= len1 - len2; i++) {
            int s = i, j = 0;
            while (s < len1 && j < len2) {
                if (text[s] == pattern[j]) j++;
                s++;
            }
            if (j == len2) {
                if (s - i < minLen) {
                    START = i;
                    END = s - 1;
                    minLen = s - i;
                }
            }
        }
        cout << START << ' ' << END << endl;
    }
    return 0;
}
