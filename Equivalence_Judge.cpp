#include "Equivalence_Judge.h"

void Judge::equivalence_judge()
{
    Running_OJ program1(file1, "output1.txt");
    Running_OJ program2(file2, "output2.txt");
    program1.program_running();
    program2.program_running();
    string buf1, buf2;
    ifstream infile1("output1.txt");
    ifstream infile2("output2.txt");
    getline(infile1, buf1);
    getline(infile2, buf2);
    while(infile1 || infile2)
    {
        if (buf1 != buf2)
        {
            equal = false;
            return;
        }
        getline(infile1, buf1);
        getline(infile2, buf2);
        if ((infile1 && !infile2) || (infile2 && !infile1))
        {
            equal = false;
            return;
        }
    }
    equal = true;
}