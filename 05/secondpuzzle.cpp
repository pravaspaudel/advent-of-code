#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void mergeRanges(vector<vector<ll>> &rangesList)
{
    sort(rangesList.begin(), rangesList.end());

    vector<vector<ll>> mergedRange;
    mergedRange.push_back(rangesList[0]);

    for (size_t i = 1; i < rangesList.size(); i++)
    {
        ll currentStart = rangesList[i][0];
        ll currentEnd = rangesList[i][1];
        ll &lastEnd = mergedRange.back()[1];

        cout << " for i = " << i << endl;
        cout << " current start is " << currentStart << " current end is " << currentEnd << " and last end is" << lastEnd << endl;

        if (currentStart <= lastEnd)
        {
            lastEnd = max(lastEnd, currentEnd); // merge
            cout << " in if statement last end is" << lastEnd << endl;
        }
        else
        {
            cout << " in else statement current start = " << currentStart << " and " << currentEnd << endl;
            mergedRange.push_back({currentStart, currentEnd});
        }
    }

    ll sum = 0;
    for (auto &r : mergedRange)
    {
        sum += (r[1] - r[0] + 1);
    }
    cout << " sum is " << sum << endl;
}

int main()
{
    ifstream file("input.txt");
    string line;
    vector<vector<ll>> rangesList;

    if (!file)
    {
        cout << "Cannot open the file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        int dash = line.find('-');
        if (dash != string::npos)
        {
            rangesList.push_back({stoll(line.substr(0, dash)), stoll(line.substr(dash + 1))});
        }
    }

    file.close();

    mergeRanges(rangesList);
    return 0;
}
