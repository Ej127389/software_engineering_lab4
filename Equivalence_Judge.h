#pragma once
#include "stdc++.h"
#include "OJ_running.h"

using namespace std;

class Judge
{
    string file1;
    string file2;
    bool equal;
public:
    Judge(string name1, string name2) : file1(name1), file2(name2), equal(true){}
    bool Is_equal() { return equal; }
    void equivalence_judge();
};