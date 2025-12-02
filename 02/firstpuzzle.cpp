#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void process_input(vector<string> &inputRanges)
{
    ll sumofIds = 0;
    for (const string &input : inputRanges)
    {
        cout << "input is " << input << endl;
        size_t locateDash = input.find("-");

        ll low = stoll(input.substr(0, locateDash));
        ll high = stoll(input.substr(locateDash + 1));

        while (low <= high)
        {
            string str = to_string(low);
            if (str.length() % 2 != 0)
            {
                low++;
                continue;
            }
            size_t l = str.length() / 2;
            if (str.substr(0, l) == str.substr(l))
            {
                // cout << " double digit is " << low << endl;
                sumofIds += low;
            }
            low++;
        }
        cout << "sum is now " << sumofIds << endl;
    }
    cout << "sum of Ids are " << sumofIds << endl;
};

int main()
{
    vector<string> inputs;

    ifstream file("input.txt");
    string line;

    if (!file)
    {
        cout << "file cannot be opened" << endl;
        return 0;
    }

    while (getline(file, line, ','))
    {
        auto iter = remove(line.begin(), line.end(), ' ');

        line.erase(iter, line.end());

        inputs.push_back(line);
    }

    // for (const string &i : inputs)
    // {
    //     cout << i << endl;
    // }

    file.close();

    process_input(inputs);

    return 0;
}
