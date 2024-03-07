#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <chrono>

using namespace std;

void naive(string &str, string &substr)
{
    int m = str.length(), n = substr.length(), j;
    for (int i = 0; i <= m - n; i++)
    {
        if (str[i] == substr[0])
        {
            j = 1;
            while (str[i + j] == substr[j] && j < n)
                ++j;
            if (j == n)
            {
                cout << "Matching" << endl;
                continue;
            }

            j = 1;
            while ((str[i + j] - substr[j]) >= (str[i + j - 1] - substr[j - 1]) && j < n)
                ++j;
            if (j == n)
            {
                cout << "First match increasing" << endl;
                continue;
            }

            j = 1;
            while (((str[i + j] - substr[j]) <= (str[i + j - 1] - substr[j - 1])) && j < n)
                ++j;

            if (j == n)
                cout << "First match decreasing" << endl;
            else
                cout << "Not matching" << endl;
        }
        else
            cout << "Not matching" << endl;
    }
}
int main()
{
    string str, substr;
    cin >> str >> substr;
    vector<int> match;
    // match = rabin_karp(str, substr);

    // for (auto x : match)
    //     cout << x << endl;
    auto start = std::chrono::high_resolution_clock::now();

    naive(str, substr);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << endl;
    return 0;
}
