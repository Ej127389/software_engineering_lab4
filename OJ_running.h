#pragma once
#include "stdc++.h"

using namespace std;

class Running_OJ
{
    string filename;
    string result_filename;
public:
    Running_OJ(string name, string resultname) : filename(name), result_filename(resultname){}
    void program_running();
};