#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void handle_beams(vector<string> &lines)
{
    int find_starting_point = lines[0].find('S');
    int splitted_count = 0;

    vector<int> beams; // indexes of beams
    beams.push_back(find_starting_point);

    for (size_t row = 1; row < lines.size(); row++)
    {
        vector<int> current = beams;
        cout << endl;
        cout << " currently beams are ";

        for (int beam : current)
        {
            cout << "for row = " << row << " and " << "beam = " << beam;
            if (lines[row][beam] == '^')
            {
                if (beam > 0 && beam < lines[row].size() - 1)
                {
                    int right = beam + 1;
                    int left = beam - 1;

                    if (find(beams.begin(), beams.end(), right) == beams.end())
                    {
                        beams.push_back(right);
                        splitted_count++;
                        cout << " pushed " << right;
                    }

                    if (find(beams.begin(), beams.end(), left) == beams.end())
                    {
                        beams.push_back(left);
                        splitted_count++;
                        cout << " pushed " << left;
                    }
                }
                beams.erase(find(beams.begin(), beams.end(), beam));
            }
        }

        cout << " last ko beam ko length " << beams.size() << endl;
    }

    cout << " splitted _ count is " << splitted_count << endl;
    cout << " final result is" << splitted_count - beams.size() + 1 << endl;
};

int main()
{
    ifstream file("input1.txt");
    vector<string> lines;
    string line;

    if (!file)
    {
        cout << " file cannot be read" << endl;
        return 0;
    }

    while (getline(file, line))
    {
        // cout << line << endl;
        lines.push_back(line);
    }

    file.close();

    handle_beams(lines);

    return 0;
}
