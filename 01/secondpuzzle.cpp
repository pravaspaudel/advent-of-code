#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void puzzle2(vector<string> &input)
{

    int num = 50;
    int count = 0;
    for (const string &element : input)
    {
        char ch = element[0];
        int val = stoi(element.substr(1));

        for (int i = 0; i < val; i++)
        {
            if (ch == 'L')
            {
                num--;
                if (num < 0)
                {
                    num = 99; // wrapping around
                }
            }
            else
            {
                num++;
                if (num > 99)
                {
                    num = 0;
                }
            }

            if (num == 0)
            {
                count++;
            }
        }
    }
    cout << " password is " << count << endl;
};

int main()
{

    ifstream file("input2.txt");
    vector<string> input2;

    if (!file)
    {
        cout << "cannot open the file " << endl;
        return 0;
    }

    string line;
    while (getline(file, line))
    {
        input2.push_back(line);
    }

    file.close();

    puzzle2(input2);
    return 0;
}