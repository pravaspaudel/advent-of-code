#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void print_array(vector<vector<char>> &array)
{
    for (int row = 0; row < array.size(); row++)
    {
        for (int col = 0; col < array[0].size(); col++)
        {
            cout << array[row][col] << " ";
        }
        cout << endl;
    }
};

int check_points(int i, int j, vector<vector<char>> &a)
{
    cout << " for point " << i << " , " << j << endl;
    int count = 0;

    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (k == i && l == j)
            {
                continue;
            }
            if (k >= 0 && k < a.size() && l >= 0 && l < a[0].size())
            {
                cout << " for " << k << " , " << l << " point is " << a[k][l] << endl;
                if (a[k][l] == '@')
                {
                    count++;
                }
            }
        }
    }
    cout << " count is " << count << endl;
    return count;
}

void find_possible_lifts(vector<vector<char>> &a)
{
    int result = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] == '.')
            {
                continue;
            }
            int count = check_points(i, j, a);
            if (count < 4)
            {
                result++;
            }
        }
    }
    cout << " result is " << result << endl;
};

int main()
{
    ifstream file("input1.txt");
    vector<vector<char>> input;
    string line;

    if (!file)
    {
        cout << " cannot opened the file " << endl;
    }

    while (getline(file, line))
    {
        vector<char> r;

        for (int i = 0; i < line.length(); i++)
        {
            r.push_back(line[i]);
        }
        input.push_back(r);
    };

    cout << " array is " << endl;
    print_array(input);

    find_possible_lifts(input);

    file.close();
}