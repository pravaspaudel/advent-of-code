#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_part1(vector<vector<ll>> &numbers, vector<char> &ops)
{
    ll final_sum = 0;

    for (int i = 0; i < numbers[0].size(); i++)
    {
        ll multiplied = 1;
        ll added = 0;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (ops[i] == '*')
            {
                multiplied *= numbers[j][i];
                cout << " operation was multiplied" << endl;
            }
            if (ops[i] == '+')
            {
                added += numbers[j][i];
                cout << " operation was addition" << endl;
            }
        }

        if (added > 0)
        {
            cout << " operation was added";
            final_sum += added;
        }
        else
        {
            cout << " operation was multiplied";
            final_sum += multiplied;
        }
    }
    cout << " final sum is " << final_sum << endl;
};

int main()
{
    ifstream file("input1.txt");
    if (!file)
    {
        cout << "file cannot be opened\n";
        return 0;
    }

    string line;
    vector<vector<ll>> numbers;
    vector<char> ops;

    while (getline(file, line))
    {

        if (line.find_first_of("*+") != string::npos)
        {
            for (char c : line)
            {
                if (c == '*' || c == '+')
                {
                    ops.push_back(c);
                }
            }
        }
        else
        {
            stringstream ss(line);
            vector<ll> row;
            ll x;

            while (ss >> x)
                row.push_back(x);

            numbers.push_back(row);
        }
    }

    solve_part1(numbers, ops);

    return 0;
}
