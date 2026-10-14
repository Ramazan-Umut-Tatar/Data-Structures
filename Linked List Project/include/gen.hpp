#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>

using namespace std;

class Gen{

public:

    string bilgi;
    Gen* onceki;
    Gen* sonraki;


    Gen(string);
    ~Gen();

};

#endif