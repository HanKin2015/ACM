#ifndef BOY_H
#define BOY_H
#include <iostream>
using namespace std;

class Boy
{
public:
    Boy();   
    virtual ~Boy() {};    
    string name;
    void display();
};
#endif
