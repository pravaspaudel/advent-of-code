#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print_array(vector<vector<char>> &a)
{

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
};

int check_points(int i, int j, vector<vector<char>> &a)
{
    int count = 0;
    for (int row = i - 1; row <= i + 1; row++)
    {
        for (int col = j - 1; col <= j + 1; col++)
        {
            if (row == i && col == j)
            {
                continue;
            }

            if (row >= 0 && col >= 0 && row < a.size() && col < a[0].size())
            {
                if (a[row][col] == '@')
                {
                    count++;
                }
            }
        }
    }
    return count;
};

int solve_puzzle_two(vector<vector<char>> &arr)
{
    int result = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == '.' || arr[i][j] == 'x')
            {
                continue;
            }

            int c = check_points(i, j, arr);

            if (c < 4)
            {
                arr[i][j] = 'x';
                result++;
            }
        }
    }
    return result;
};

int main()
{
    ifstream file("input1.txt");
    vector<vector<char>> input;
    string line;

    if (!file)
    {
        cout << " error while opening the file" << endl;
    }

    while (getline(file, line))
    {
        vector<char> r;
        for (int i = 0; i < line.length(); i++)
        {
            r.push_back(line[i]);
        }
        input.push_back(r);
    }

    // print_array(input);

    int final_result = 0;
    int res;

    while (res > 0)
    {
        res = solve_puzzle_two(input);
        cout << "result is " << res << endl;
        final_result += res;
    }
    cout << " final result is " << final_result << endl;

    file.close();
}
