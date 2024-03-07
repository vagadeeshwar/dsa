#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

int naive(string &str, string &substr)
{
    int m = str.length(), n = substr.length();
    for (int i = 0; i < m - n + 1; i++)
    {
        if (str[i] == substr[0])
        {
            int j = 1;
            while (str[i + j] == substr[j] && j < n)
                ++j;
            if (j == n)
                return i;
        }
    }
    return -1;
}
// ascii taken as hashing function, here d is alphabet length, q is a prime number to be used as the mod
// O(n-m+1) or O(m*(n-m+1))
// don't give q as INT_MAX! for the same reason as comment under h calculation...small prime numbers like 101,131 are decent
vector<int> rabin_karp(string &str, string &substr, int d = 128, int q = 101) // returns vector with all indices of occurence
{
    int n = str.length(), m = substr.length();
    int sub_hash = 0, str_hash = 0, h = 1;
    vector<int> match;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q; // Don't calculate directly....d^m-1 can be a large number and hence when that number crosses INT_MAX....it will be reset to INT_MIN

    for (int i = 0; i < m; i++)
    {
        sub_hash = (sub_hash * (d) + substr[i]) % q; // Initial hash are calculated O(n)
        str_hash = (str_hash * d + str[i]) % q;
    }

    // cout << sub_hash << endl
    //      << str_hash << endl;

    for (int i = 0; i < n - m + 1; i++) // O(m(n-m))
    {
        if (str_hash == sub_hash)
        {
            int j = 0;
            for (; j < m; j++)
                if (str[i + j] != substr[j])
                    break;
            if (j == m)
                match.push_back(i);
        }
        // if (i < n - m)                                                 // this checking is there in many books...but works fine without it also
        str_hash = (d * (str_hash - str[i] * h) + str[i + m]) % q; // Efficient calculation of further hash values in str O(1)
        if (str_hash < 0)                                          // -ve value implies we are going left of the first value(0) hence -1 is same as q-1(which is the last value of bucket)
            str_hash += q;                                         // if hash is -ve, increment by mod value
    }

    if (match.empty())
        match.push_back(-1);

    return match;
}

int main()
{
    string str, substr;
    cin >> str >> substr;
    vector<int> match;
    match = rabin_karp(str, substr);

    for (auto x : match)
        cout << x << endl;

    return 0;
}