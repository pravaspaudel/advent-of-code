#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void puzzle_1(vector<string> &input)
{
    int num = 50;
    int count = 0;
    for (string &element : input)
    {
        char ch = element[0];
        int val = stoi(element.substr(1));

        if (element.empty())
            continue;

        if (ch == 'L')
        {
            num = (num - val + 100) % 100;
            if (num == 0)
            {
                count++;
            }
        }
        else if (ch == 'R')
        {
            num = (num + val) % 100;
            if (num == 0)
            {
                count++;
            }
        }
    }
    cout << " password is " << count << endl;
}

int main()
{
    // ifstream file("small_input.txt");
    ifstream file("input1.txt");
    vector<string> input;

    if (!file)
    {
        cout << "unable to open the file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line))
    {
        input.push_back(line);
    }
    file.close();

    // for (string i : input)
    // {
    //     cout << i << " ";
    // }

    puzzle_1(input);
    return 0;
}
