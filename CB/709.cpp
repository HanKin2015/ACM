#include <iostream>
#include <cmath>
#include <cstdio>

#define pi acos(-1.0)

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n, x1, x2, r;
	cin >> n;
	while (n--)
	{
		cin >> x1 >> x2 >> r;
		if (x2 - x1 > 2 * r)
		{
		    double shadow = 0;
			printf("%.2f\n", shadow);
		}
		else
		{
			double d = double(x2 - x1) / 2;
			double h = sqrt(r*r - d*d);
			double ang = asin(d / r);
			double aver1 = ang / 2 * r*r;
			double aver2 = h*d / 2;
			double aver = aver1 - aver2;
			double shadow = 2 * ((r - h)*d - aver);
			printf("%.2f\n", shadow);
		}
	}
	return 0;
}

