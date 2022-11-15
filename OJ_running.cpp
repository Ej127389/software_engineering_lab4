#include "OJ_running.h"

void Running_OJ::program_running()
{
    int pos = 0;
    for (int i = 0; i < filename.length(); i++)
    {
        if(filename[i]=='.')
        {
            pos = i;
            break;
        }
    }
    ofstream outfile(result_filename);
    outfile.close();
    string name = filename.substr(0, pos);
    string cmd1 = "g++ -std=c++14 " + filename + " -o " + name + ".out";
    system(cmd1.c_str());
    string buf1;
    ifstream infile1("input.txt");
    getline(infile1, buf1);
    while(infile1)
    {
        ofstream outfile1("1.txt");
        outfile1 << buf1 << endl;
        outfile1.close();
        string cmd2 = name + ".out <1.txt >2.txt";
        system(cmd2.c_str());
        string buf2;
        ifstream infile2("2.txt");
        getline(infile2, buf2);
        infile2.close();
        ofstream outfile2(result_filename, ios::app);
        outfile2 << buf2;
        getline(infile1, buf1);
        if(infile1)
        {
            outfile2 << endl;
        }
        outfile2.close();
        
    }
    infile1.close();
    system("rm 1.txt");
    system("rm 2.txt");
    string cmd3 = "rm " + name + ".out";
    system(cmd3.c_str());
}