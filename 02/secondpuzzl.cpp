#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// a number of x digits can have repeating patterns of length dividing x
void find_patterns(vector<string> &inputRanges)
{
    ll sum = 0;
    for (const string &input : inputRanges)
    {
        cout << "input is " << input << endl;
        size_t locateDash = input.find("-");

        ll low = stoll(input.substr(0, locateDash));
        ll high = stoll(input.substr(locateDash + 1));

        while (low <= high)
        {
            string str = to_string(low);
            int length = str.length();

            for (int k = 1; k < length; k++)
            {
                if (length % k != 0)
                    continue;

                string pattern = str.substr(0, k);
                string org = "";
                int repeatedTimes = length / k;

                for (int i = 0; i < repeatedTimes; i++)
                {
                    org += pattern;
                }

                if (org == str)
                {
                    sum += low;
                    break;
                }
            }
            low++;
        }
    }

    cout << "Sum of invalid IDs: " << sum << endl;
};

int main()
{
    vector<string> inputs;

    fstream file("input2.txt");

    if (!file)
    {
        cout << "Cannot open the file. Error" << endl;
        return 1;
    }

    string line;
    while (getline(file, line, ',')) // comma is a delimiter
    {
        auto h = remove(line.begin(), line.end(), ' ');
        line.erase(h, line.end());
        inputs.push_back(line);
    }

    find_patterns(inputs);

    file.close();

    return 0;
}
