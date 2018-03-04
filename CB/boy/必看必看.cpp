#include <bits/stdc++.h>
using namespace std;

int main()
{
    //int seed = time(0);
    //srand(time(0));
    //for(int i = 0; i < 10; i++)
    //    cout << rand() << endl;

    //cout << endl;
    clock_t startTime = clock();
	long long cnt = 0;
	for (long long i = 0; i < 1e8; i++) { cnt++; }
	cout << cnt << endl;
	printf("Run Time:%f s\n\n", ((double)(clock() - startTime) / CLOCKS_PER_SEC));

	startTime = clock();
	double t1 = 0, t2 = 0;
	for(int i = 0; i < 5; i++) {
        cnt = 0;
        clock_t T1 = clock();
        for (long long i = 0; i < 1e8; i++) { cnt++; }
        t1 += ((double)(clock() - T1) / CLOCKS_PER_SEC);

        clock_t T2 = clock();
        for (long long i = 0; i < 1e8 / 2; i++) { cnt++; }
        t2 += ((double)(clock() - T2) / CLOCKS_PER_SEC);
	}
    printf("Run Time:%f s\n\n", ((double)(clock() - startTime) / CLOCKS_PER_SEC));

    cout << t1 << endl;
    cout << t2 << endl;
    return 0;
}
