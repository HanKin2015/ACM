#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
	int n = grid.size();
	int m = grid[0].size();
	int sum = n * m;
	vector<vector<int>> ret = grid;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int pos = i * m + j;
			pos = (pos + k) % sum;
			ret[pos / m][pos % m] = grid[i][j];
		}
	}
	//cout << ret[0][1] << endl;
	return ret;
}

int main()
{
   	vector<vector<int>> grid;
   	std::vector<int> v;
   	v.push_back(1);
   	v.push_back(2);
	grid.push_back(v);
	shiftGrid(grid, 1);
   	return 0;
}