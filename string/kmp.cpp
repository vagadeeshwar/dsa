#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

void computeLPSArray(string &pat, int M, vector<int> &lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp(string &txt, string &pat)
{
    int M = pat.length(), N = txt.length();
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector<int> lps(M, 0), arr;

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            // 			printf("Found pattern at index %d ", i - j);
            arr.push_back(i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return arr;
}

int main()
{
    string str, substr;
    cin >> str >> substr;
    vector<int> match;
    match = kmp(str, substr);

    for (auto x : match)
        cout << x << endl;

    return 0;
}