#include <iostream>
#include <hash_map>
using namespace std;
//using namespace stdext;
//#include <ext/hash_map>
using namespace __gnu_cxx;
//The include file <ext/hash_map> refers to the GNU extension hash map class and this is declared in namespace __gnu_cxx.

int main()
{
    hash_map<string, int> temp;
    if(temp["ds"].find()) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}

