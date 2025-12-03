#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

using ll = long long;

const int num_digits = 12;

ll stack_to_string(stack<int> s)
{
    vector<int> v;
    string result = "";
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }

    size_t i = v.size();
    while (i > 0)
    {
        i--;
        result += to_string(v[i]);
    }
    return stoll(result);
};

ll largest_joltage(const string &s)
{
    stack<int> st;
    int len = s.length();
    int remaining = len - num_digits; // number of digits we need to delete

    for (char ch : s)
    {
        int digit = ch - '0';

        while (!st.empty() && st.top() < digit && remaining > 0)
        {
            st.pop();
            remaining--;
        }
        st.push(digit);
    }
    while (st.size() > num_digits)
    {
        st.pop();
    }

    return stack_to_string(st);
};

void process_input(vector<string> &input)
{
    ll sum = 0;
    for (string &digit : input)
    {
        sum += largest_joltage(digit);
    }
    cout << "sum is " << sum << endl;
};

int main()
{
    ifstream file("input.txt");
    string line;
    vector<string> input;

    if (!file)
    {
        cout << " file cannot be opened " << endl;
    }

    while (getline(file, line))
    {
        input.push_back(line);
    }

    file.close();

    process_input(input);

    return 0;
}