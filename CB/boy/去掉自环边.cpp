#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *file = fopen("email-Eu-core.txt", "r");
    FILE *handle = fopen("as20graph-handle.txt", "w");
    int cnt = 0;
    while(!feof(file)) {
        cnt++;
        char str[255];
        //fscanf(file, "%s", str); //可能是空格的原因
        fgets(str, 255, (FILE*)file);
        fprintf(handle, "%s", str);
        cout << str;
        if(cnt == 4) break;
    }
    while(!feof(file)) {
		int u, v;
		fscanf(file, "%d\t%d\n", &u, &v);
		if(u != v) {
            fprintf(handle, "%d\t%d\n", u, v);
		}
		else {
            cout << u << '\t' << v << endl;
		}
    }
    fclose(file);
    fclose(handle);
    return 0;
}
