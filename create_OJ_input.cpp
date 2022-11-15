#include "create_OJ_input.h"

void Create_input::create()
{
    ifstream infile(format_file_name);
    string buf;
    getline(infile, buf);
    infile.close();
    string name, l, r;
    Type temp;
    int flag = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        if(buf[i] == ' ' || i == buf.length() - 1)
        {
            temp.type_name = name;
            if (name != "char")
            {
                temp.left = stoi(l);
                temp.right = stoi(r);
            }
            types.push_back(temp);
            name.clear();
            l.clear();
            r.clear();
            flag = 0;
            continue;
        }
        if(buf[i] == ')')
        {
            continue;
        }
        if(buf[i] == '(')
        {
            flag = 1;
            continue;
        }
        if(buf[i] == ',')
        {
            flag = 2;
            continue;
        }
        if(flag == 0)
        {
            name += buf[i];
        }
        if(flag == 1)
        {
            l += buf[i];
        }
        if(flag == 2)
        {
            r += buf[i];
        }
    }
    ofstream outfile("input.txt");
    for (int i = 0; i < num_of_input; i++)
    {
        for (int j = 0; j < types.size(); j++)
        {
            if (types[j].type_name == "int")
            {
                int n = rand() % (types[j].right - types[j].left + 1) + types[j].left;
                outfile << n;
            }
            else if(types[j].type_name == "char")
            {
                char c;
                if (rand() % 2 == 0)
                {
                    c = 'a' + rand() % 26;
                }
                else
                {
                    c = 'A' + rand() % 26;
                }
                outfile << c;
            }
            else if(types[j].type_name == "string")
            {
                string str;
                int len = rand() % (types[j].right - types[j].left + 1) + types[j].left;
                for (int k = 0; k < len; k++)
                {
                    char c;
                    if (rand() % 2 == 0)
                    {
                        c = 'a' + rand() % 26;
                    }
                    else
                    {
                        c = 'A' + rand() % 26;
                    }
                    str += c;
                }
                outfile << str;
            }
            if (j != types.size() - 1)
            {
                outfile << " ";
            }
        }
        if (i != num_of_input - 1)
        {
            outfile << endl;
        }
    }
    outfile.close();
}