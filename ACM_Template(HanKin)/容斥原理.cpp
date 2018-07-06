#include <iostream>
using namespace std;

int main()
{
    double p[3] = {0.2, 0.2, 0.6};
    double sum = 0;

    for (int msk=1; msk<(1<<3); ++msk) {
        double mult = 1;
        int bits = 0;
        for (int i=0; i < 3; ++i) {
            if (msk & (1<<i)) {
                ++bits;
                mult -= p[i];
            }
        }
        double cur = 1.0 / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }
    cout << sum << endl;
    return 0;
}
