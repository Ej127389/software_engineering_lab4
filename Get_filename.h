#pragma once
#include "stdc++.h"

using namespace std;

class Get_filename
{
    string dir_name;
public:
    Get_filename(string dir) : dir_name(dir){}
    vector<string> get_cpp_name_list();
    vector<string> get_dir_name_list();
};