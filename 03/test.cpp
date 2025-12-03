#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;
using ll = long long;

const int DIGITS = 12;

string make_largest_joltage(const string &s)
{
    int n = s.size();
    int k = n - DIGITS;
    string result;

    for (char c : s)
    {
        while (!result.empty() && result.back() < c && k > 0)
        {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    while (result.size() > DIGITS)
        result.pop_back();

    return result;
}

void process_input(vector<string> &input)
{
    ll total_sum = 0;

    for (string &line : input)
    {
        string best = make_largest_joltage(line);

        ll value = stoll(best);

        total_sum += value;

        cout << best << endl;
    }

    cout << total_sum << endl;
}

int main()
{
    ifstream file("pinput.txt");
    string line;
    vector<string> input;

    if (!file)
    {
        cout << "file cannot be opened" << endl;
        return 1;
    }

    while (getline(file, line))
        input.push_back(line);

    file.close();

    process_input(input);

    return 0;
}
