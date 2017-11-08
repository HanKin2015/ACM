#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ofstream examplefile("example.txt");
    if (examplefile.is_open())
    {
        examplefile << "This is a line.\n";
        examplefile << "This is another line.\n";
        examplefile.close();
    }

    char buffer[256];
    ifstream examplefile("example.txt");
    if (! examplefile.is_open())
    {
        cout << "Error opening file"; exit (1);
    }
    while (!examplefile.eof())
    {
        examplefile.getline(buffer,100);
        cout<<buffer<< endl;
    }
    return 0;
}
