/* study_string.cpp
 *
 * 学习string库
 *
 * author: hankin
 * date  : 2021.07.09
 *
 * Copyright (c) 2021 HanKin. All rights reserved.
 */
 
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string skr = "";
	int t = 9;
	for (int i = 0; i < 5; i++)
			skr += to_string(t) + "_";
	cout << skr << endl;


	cout << R"()" << endl;
	return 0;
}