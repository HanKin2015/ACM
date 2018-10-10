#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

//double err = 1e-9;
double getDistance(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2) * (x1-x2) * 1.0+ (y1-y2) * (y1-y2) * 1.0);
}

const int maxn = 1e6;


int main(){
//	cout << getDistance(1, 2, 3, 4)  << endl;
	int N;
	cin >> N;
	int points[2002][2];

	double sum_x = 0;
	double sum_y = 0;

	int minx = maxn, miny = maxn, maxy = -maxn, maxx = -maxn;
	for(int i = 1; i <= N; i ++){
		int _x, _y;
		cin >> _x;
		cin >> _y;
		sum_x += _x;
		sum_y += _y;
		points[i][0] = _x;
		points[i][1] = _y;
		minx = min(minx, _x);
		miny = min(miny, _y);
		maxx = max(maxx, _x);
		maxy = max(maxy, _y);
	}

	int c_x = 0;
	int c_y = 0;

	c_x = int(sum_x/N + 0.5);
	//c_x = sum_x/N;
	c_y = int(sum_y/N + 0.5);
	//c_y = sum_y/N;
//	cout << c_x << " " << c_y;


    double ans = 1e9;
	for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            double sum1 = 0;
            for(int k = 1; k <= N; k ++){
                sum1 += getDistance(points[k][0], points[k][1], i, j);
            }
            if (sum1 < ans) {
                ans = sum1;
            }
        }
	}


	printf("%.4f\n", ans);
	//cout << x << ' ' << y << endl;

}

/*
样例1:
3
1 1
2 2
3 3
样例2:
5
1 4
2 3
5 2
3 5
4 1

样例1:
2.8284
样例2:
9.6410

*/

