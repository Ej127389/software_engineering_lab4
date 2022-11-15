#pragma once
#include "stdc++.h"

using namespace std;

struct Type
{
    string type_name;
    int left;
    int right;
};

class Create_input
{
    string format_file_name;
    int num_of_input;
    vector<Type> types;

public:
    Create_input(string name = "stdin_format.txt", int num = 5): format_file_name(name), num_of_input(num) {}
    void create();
};