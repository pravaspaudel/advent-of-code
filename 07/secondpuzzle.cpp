#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

// creating a custom hash map
struct pair_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

ll back_track_cache(vector<string> &lines, int row, int col, unordered_map<pair<int, int>, ll, pair_hash> &cache)
{

    if (col < 0 || col >= lines[0].size())
    {
        return 0;
    }
    if (row == lines.size() - 1) // last row reached
    {
        return 1;
    }

    pair<int, int> key = {row, col};

    if (cache.find(key) != cache.end())
    {
        return cache[key];
    }

    ll sum_path = 0;

    if (lines[row][col] == '.')
    {
        sum_path += back_track_cache(lines, row + 1, col, cache);
    }
    else if (lines[row][col] == '^')
    {
        sum_path += back_track_cache(lines, row, col + 1, cache);
        sum_path += back_track_cache(lines, row, col - 1, cache);
    }

    cache[pair<int, int>{row, col}] = sum_path;
    return sum_path;
}

// no caching works fine only for smaller input
int back_track(vector<string> &lines, int row, int col)
{
    if (col > lines[0].size() - 1 || col < 0)
    {
        return 0;
    }

    if (row == lines.size() - 1)
    {
        return 1;
    }

    int paths = 0;

    if (lines[row][col] == '.')
    {
        paths += back_track(lines, row + 1, col);
    }
    else if (lines[row][col] == '^')
    {
        paths += back_track(lines, row, col - 1);
        paths += back_track(lines, row, col + 1);
    }
    cout << " paths is" << paths << endl;
    return paths;
};

int main()
{
    ifstream file("input1.txt");

    if (!file)
    {
        cout << " file cannot be opened" << endl;
    }

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();

    int starting_col = lines[0].find('S');
    int row = 1;

    // cout << back_track(lines, row, starting_col);

    unordered_map<pair<int, int>, ll, pair_hash> cache;

    cout << back_track_cache(lines, row, starting_col, cache);

    return 0;
}
