#include <iostream>
#include <set>
#include <math.h>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

double calculate_distance(vector<ll> &point1, vector<ll> &point2)
{
    double distance = 0;

    for (int i = 0; i < point1.size(); i++)
    {
        ll diff = point1[i] - point2[i];
        distance += diff * diff;
    }
    return sqrt(double(distance));
};

map<double, vector<vector<ll>>> find_shortest_distance(vector<vector<ll>> &points)
{
    map<double, vector<vector<ll>>> m;

    for (int i = 0; i < points.size(); i++)
    {
        vector<double> dist;
        for (int j = i + 1; j < points.size(); j++)
        {
            double val = calculate_distance(points[i], points[j]);
            m[val] = {points[i],
                      points[j]};
        }
    }
    return m;
};

vector<vector<ll>> find_closest_points(map<double, vector<vector<ll>>> &m, int n) // numbers of points to pass
{
    vector<vector<ll>> sortedDistances;

    int i = 0;

    for (auto &[key, val] : m)
    {
        if (i >= n)
        {
            break;
        }
        // cout << " for key = " << key << endl;

        for (auto &points_vector : m[key])
        {
            vector<ll> dis;
            for (auto &p : points_vector)
            {
                dis.push_back(p);
            }
            sortedDistances.push_back(dis);
            // cout << endl;
        }
        i++;
    }

    return sortedDistances;
};

// void print_simple_array(vector<ll> &ar)
// {

//     cout << " Single array is ";
//     for (auto x : ar)
//     {
//         cout << x << "  ";
//     }
//     cout << endl;
// };

// void print_second_array(vector<vector<ll>> &ar)
// {

//     cout << " second wala array is ";

//     for (auto x : ar)
//     {
//         for (auto &y : x)
//         {
//             cout << y << " ";
//         }
//         cout << endl;
//     }
// };

// void print_third_array(vector<vector<vector<ll>>> &ar)
// {

//     cout << " second wala array is ";

//     for (auto x : ar)
//     {
//         for (auto &y : x)
//         {
//             for (auto &p : y)
//             {
//                 cout << p << " ";
//             }
//             cout << " hehe ";
//         }
//         cout << endl;
//     }
// };

void calculate_final_result(vector<vector<ll>> &sortedDistances)
{
    vector<vector<vector<ll>>> connected;

    for (int i = 0; i + 1 < sortedDistances.size(); i += 2)
    {

        vector<ll> point1 = sortedDistances[i];
        vector<ll> point2 = sortedDistances[i + 1];

        int grp_index_1 = -1, grp_index_2 = -1; // index of group for point 1 and point 2

        for (int j = 0; j < connected.size(); j++)
        {

            if (find(connected[j].begin(), connected[j].end(), point1) != connected[j].end())
            {
                grp_index_1 = j;
            }

            if (find(connected[j].begin(), connected[j].end(), point2) != connected[j].end())
            {
                grp_index_2 = j;
            }
        }

        if (grp_index_1 == -1 && grp_index_2 == -1)
        {
            connected.push_back({point1, point2});
        }
        else if (grp_index_1 != -1 && grp_index_2 == -1)
        {
            connected[grp_index_1].push_back(point2);
        }
        else if (grp_index_1 == -1 && grp_index_2 != -1)
        {
            connected[grp_index_2].push_back(point1);
        }
        else if (grp_index_1 != grp_index_2)
        {
            connected[grp_index_1].insert(connected[grp_index_1].end(), connected[grp_index_2].begin(), connected[grp_index_2].end());

            connected.erase(connected.begin() + grp_index_2);
        }
    }

    vector<int> sizes;
    for (auto &grp : connected)
    {
        sizes.push_back(grp.size());
    }

    sort(sizes.rbegin(), sizes.rend());

    ll result = 1;
    for (int i = 0; i < min(3, (int)sizes.size()); i++)
    {
        result *= sizes[i];
        cout << " size is " << sizes[i] << endl;
    }

    cout << "Product of three largest connected group sizes: " << result << endl;
}

int main()
{
    vector<vector<ll>> three_D_points;

    ifstream file("input1.txt");

    if (!file)
    {
        cout << " file cannot be opened " << endl;
    }
    string line;
    vector<string> lines;

    while (getline(file, line))
    {
        string num = "";
        vector<ll> point;
        for (char ch : line)
        {
            if (ch == ',')
            {
                point.push_back(stoll(num));
                num = "";
            }
            else
            {
                num += ch;
            }
        }

        if (num != "")
        {
            point.push_back(stoll(num));
        }

        three_D_points.push_back(point);
    }

    file.close();

    map<double, vector<vector<ll>>> m = find_shortest_distance(three_D_points);

    vector<vector<ll>> sortedDistances = find_closest_points(m, 1000);

    calculate_final_result(sortedDistances);

    return 0;
}
