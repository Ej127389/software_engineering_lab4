#include "Get_filename.h"

vector<string> Get_filename::get_cpp_name_list()
{
    string cmd;
    vector<string> result;
    cmd = "ls " + dir_name + "/*.cpp >3.txt";
    system(cmd.c_str());
    string buf;
    ifstream infile("3.txt");
    getline(infile, buf);
    while(infile)
    {
        result.push_back(buf);
        getline(infile, buf);
    }
    system("rm 3.txt");
    return result;
}

vector<string> Get_filename::get_dir_name_list()
{
    string cmd;
    vector<string> result;
    cmd = "ls " + dir_name + " >3.txt";
    system(cmd.c_str());
    string buf;
    ifstream infile("3.txt");
    getline(infile, buf);
    while(infile)
    {
        buf = dir_name + "/" + buf;
        result.push_back(buf);
        getline(infile, buf);
    }
    system("rm 3.txt");
    return result;
}
