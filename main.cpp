#include "create_OJ_input.h"
#include "OJ_running.h"
#include "Get_filename.h"
#include "Equivalence_Judge.h"

using namespace std;

int main()
{
    ofstream ofs1("equal.csv");
    ofs1 << "file1,file2" << endl;
    ofs1.close();
    ofstream ofs2("inequal.csv");
    ofs2 << "file1,file2" << endl;
    ofs2.close();
    Get_filename temp1("/home/ej/input");
    vector<string> dir_list = temp1.get_dir_name_list();
    for (int i = 0; i < dir_list.size(); i++)
    {
        Get_filename temp2(dir_list[i]);
        vector<string> cpp_list = temp2.get_cpp_name_list();
        string name = dir_list[i] + "/stdin_format.txt";
        Create_input create_input(name);
        create_input.create();
        for (int j = 0; j < cpp_list.size(); j++)
        {
            for (int k = j + 1; k < cpp_list.size(); k++)
            {
                Judge judge(cpp_list[j], cpp_list[k]);
                //cout << cpp_list[j] << endl;
                //cout << cpp_list[k] << endl;
                judge.equivalence_judge();
                string final_file;
                if (judge.Is_equal())
                {
                    final_file = "equal.csv";
                }
                else
                {
                    final_file = "inequal.csv";
                }
                ofstream outfile(final_file, ios::app);
                outfile << cpp_list[j] << "," << cpp_list[k] << endl;
                outfile.close();
            }
        }
    }
    // Judge judge("/home/ej/input/4A/101036360.cpp", "/home/ej/input/4A/48762087.cpp");
    // //cout << cpp_list[j] << endl;
    // //cout << cpp_list[k] << endl;
    // judge.equivalence_judge();
    // string final_file;
    // if (judge.Is_equal())
    // {
    //     final_file = "equal.csv";
    // }
    // else
    // {
    //     final_file = "inequal.csv";
    // }
    // ofstream outfile(final_file, ios::app);
    // outfile << "/home/ej/input/4A/101036360.cpp" << "," << "/home/ej/input/4A/48762087.cpp" << endl;
    // outfile.close();
    return 0;
}