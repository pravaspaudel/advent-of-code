#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using ll = long long;
using namespace std;

void calculate_available_fresh(vector<vector<ll>> &availableRange, vector<ll> &freshlist)
{
    int count = 0;

    cout << " size of freshlist is " << freshlist.size() << endl;

    for (int i = 0; i < freshlist.size(); i++)
    {
        for (const auto &range : availableRange)
        {
            cout << "ranges is ( " << range[0] << " , " << range[1] << " ) " << endl;
            cout << "current fresh element is " << freshlist[i] << endl;
            if (range[0] <= freshlist[i] && freshlist[i] <= range[1])
            {
                count++;
                break;
            }
            cout << " count here is " << count << endl;
        }
    }
    cout << " total count is " << count << endl;
};

int main()
{
    ifstream file("input1.txt");
    string line;
    vector<vector<ll>> ranges;
    vector<ll> fresh_ingredients;

    if (!file)
    {
        cout << " file cannot be opened error" << endl;
    }

    bool passed_empty_line = false;
    while (getline(file, line))
    {
        if (line.empty())
        {
            passed_empty_line = true; // file has passed throught the empty line
            continue;
        }
        if (!passed_empty_line)
        {
            int locate_dash = line.find('-');
            ll num1 = stoll(line.substr(0, locate_dash));
            ll num2 = stoll(line.substr(locate_dash + 1));

            ranges.push_back({num1, num2});
        }
        else
        {
            fresh_ingredients.push_back(stoll(line));
        }
    }

    file.close();
    calculate_available_fresh(ranges, fresh_ingredients);

    return 0;
}
