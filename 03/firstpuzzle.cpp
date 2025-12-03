#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void print_stack(stack<int> &st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

// optimized
void largest_double_digit(vector<string> &input)
{
    const int num_digits = 2;
    int sum = 0;

    for (string &digit : input)
    {
        stack<int> st;
        int len = digit.length();
        int remain = len - num_digits; // how many digits to remove

        for (char ch : digit)
        {
            int n = ch - '0';

            while (!st.empty() && st.top() < n && remain > 0)
            {
                st.pop();
                remain--;
            }

            st.push(n);
        }

        while (remain > 0 && !st.empty())
        {
            st.pop();
            remain--;
        }

        while (st.size() > num_digits)
        {
            st.pop();
        }

        int d2 = st.top();
        st.pop();
        int d1 = st.top();
        st.pop();

        sum += d1 * 10 + d2;
    }

    cout << "sum is " << sum << endl;
}

// brute force
void find_double_digit(vector<string> &input)
{
    // for each position try to find the largest to the right
    int sum = 0;

    for (string &digit : input)
    {
        int max_num = INT_MIN;
        int num;

        for (size_t k = 0; k < digit.length(); k++)
        {
            int large = INT_MIN;
            for (size_t i = k + 1; i < digit.length(); i++)
            {
                if ((digit[i] - '0') > large)
                {
                    large = digit[i] - '0';
                }
            }
            int num = (digit[k] - '0') * 10 + large;

            max_num = max(num, max_num);
        }
        cout << "max number is " << max_num << endl;
        sum += max_num;
    }
    cout << "sum is " << sum << endl;
};

int main()
{
    ifstream file("input1.txt");
    vector<string> input;

    string line;

    while (getline(file, line))
    {
        input.push_back(line);
    }

    file.close();

    // find_double_digit(input);
    largest_double_digit(input);
    return 0;
}
