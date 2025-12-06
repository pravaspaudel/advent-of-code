#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<string> read_file(string &file_path)
{
    ifstream file(file_path);
    string line;
    vector<string> lineList;

    while (getline(file, line))
    {
        lineList.push_back(line);
    }
    return lineList;
};

vector<vector<ll>> proces_input(const vector<string> &line)
{
    vector<vector<ll>> rearrangedList;
    vector<vector<int>> total_cols; // this stores the digits indices
    vector<int> current;
    for (int i = 0; i < line[0].size(); i++) // i represents col
    {
        bool is_completely_blank = true;

        for (int j = 0; j < line.size(); j++)
        {
            if (line[j][i] != ' ')
            {
                is_completely_blank = false;
            }
        }

        if (!is_completely_blank)
        {
            current.push_back(i);
        }
        else
        {
            if (!current.empty())
            {
                total_cols.push_back(current);
                current.clear();
            }
        }
    }

    if (!current.empty()) // push the remaining ones
    {
        total_cols.push_back(current);
    }
    reverse(total_cols.begin(), total_cols.end());

    for (auto &idx : total_cols)
    {
        vector<ll> nums;
        for (int i : idx)
        {
            string number;
            for (int r = 0; r < line.size() - 1; r++)
            {
                if (line[r][i] != ' ')
                {
                    number += line[r][i];
                }
            }
            if (!number.empty())
            {
                nums.push_back(stoll(number));
            }
        }
        rearrangedList.push_back(nums);
    }
    return rearrangedList;
}

void final_solve(vector<vector<ll>> rearrangedNumbers, vector<char> operators)
{

    ll final_sum = 0;
    int i = 0;

    for (auto numbers : rearrangedNumbers)
    {
        ll multiplied = 1;
        ll added = 0;
        for (auto n : numbers)
        {
            if (operators[i] == '+')
            {
                added += n;
            }
            else if (operators[i] == '*')
            {
                multiplied *= n;
            }
        }
        if (added > 0)
        {
            final_sum += added;
        }
        else
        {
            final_sum += multiplied;
        }
        i++;
    }
    cout << " final sum is " << final_sum << endl;
}

vector<char> get_operators(const string &file_path)
{
    vector<char> operators;
    ifstream file(file_path);
    if (!file)
    {
        cout << "File cannot be opened" << endl;
    }
    string line;
    while (getline(file, line))
    {
        for (char ch : line)
        {
            if (ch == '+' || ch == '*')
            {
                operators.push_back(ch);
            }
        }
    }
    reverse(operators.begin(), operators.end());
    return operators;
}

int main()
{
    string file_path = "input1.txt";
    vector<string> input_lines = read_file(file_path);
    vector<vector<ll>> rearrangedOnes = proces_input(input_lines);

    vector<char> operators = get_operators("input1.txt");

    final_solve(rearrangedOnes, operators);
}
