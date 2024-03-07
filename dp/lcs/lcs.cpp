#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sub_seq(string str);                                                                                  // finds all the substrings of a given string
void lcs_str(string &str1, string &str2, int m, int n, vector<vector<int>> &ctable, int idx, string &lcs); // prints all the possible lcs strings
int lcs_td(string &str1, string &str2);

int lcs(string &str1, string &str2)
{

    int m = str1.length(), n = str2.length();

    vector<vector<int>> c(m + 1, vector<int>(n + 1, -1)); // ctable which stores lcs values

    for (int j = 0; j < n + 1; j++)
        c[0][j] = 0;
    for (int i = 1; i < m + 1; i++)
        c[i][0] = 0;

    // ie the base case of length 0 string is taken care of by first row&column of ctable
    for (int i1 = 1; i1 < m + 1; i1++) // ctable is taken to be of dimension (m+1)*(n+1) for simplicity sakes
    {
        for (int i2 = 1; i2 < n + 1; i2++) // so here ctable[i1][i2] gives lcs of str1[i1] & str2[i2]
        {
            if (str1[i1 - 1] == str2[i2 - 1])
                c[i1][i2] = 1 + c[i1 - 1][i2 - 1];
            else
                c[i1][i2] = max(c[i1 - 1][i2], c[i1][i2 - 1]);
        }
    }
    int lcs = c[m][n];
    vector<string> lcs_arr;
    // lcs_str(str1, str2, m, n, c, lcs - 1, string("$", lcs),lcs_arr); // To print all possible lcs strings

    return lcs;
}

int main()
{

    string str1, str2;
    cin >> str1 >> str2;

    // auto start = std::chrono::high_resolution_clock::now();

    cout << lcs(str1, str2) << endl;

    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // cout << "Time taken: " << duration.count() << endl;

    return 0;
}

// m,n are length of strings,idx is lcs-1,lcs is the lcs string(initially dummy is passed)
void lcs_str(string &str1, string &str2, int m, int n, vector<vector<int>> &ctable, int idx, string lcs, vector<string> &lcs_arr) // prints all the possible lcs strings
{                                                                                                                                 // These arguments are used for recursive call if needed
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[idx] = str1[i - 1];
            --idx;
            --i;
            --j;
        }
        else
        {
            if (ctable[i - 1][j] > ctable[i][j - 1])
                --i;
            else if (ctable[i - 1][j] < ctable[i][j - 1])
                --j;
            else
            {
                lcs_str(str1, str2, i, j - 1, ctable, idx, lcs, lcs_arr);
                --i;
            }
        }
    }

    if (find(lcs_arr.begin(), lcs_arr.end(), lcs) == lcs_arr.end())
    {
        lcs_arr.push_back(lcs);
        cout << lcs << endl;
    }
}

int lcs_aux(string &str1, string &str2, int i1, int i2, vector<vector<int>> &c)
{
    if (c[i1][i2] != -1)
        return c[i1][i2];
    if (i1 == 0 || i2 == 0)
        return 0;
    if (str1[i1 - 1] == str2[i2 - 1])
        return c[i1][i2] = 1 + lcs_aux(str1, str2, i1 - 1, i2 - 1, c);

    return c[i1][i2] = max(lcs_aux(str1, str2, i1 - 1, i2, c), lcs_aux(str1, str2, i1, i2 - 1, c));
}

int lcs_td(string &str1, string &str2)
{
    int m = str1.length(), n = str2.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, -1));

    return lcs_aux(str1, str2, m, n, c);
}

void sub_seq_aux(string &str, string substr, int i, vector<string> &arr)
{
    if (i == str.length())
    {
        arr.push_back(substr); // when end of str is reached store value into arr
        return;
    }
    sub_seq_aux(str, substr, i + 1, arr);          // Don't include current character/element
    sub_seq_aux(str, substr + str[i], i + 1, arr); // Include current character/element
}

void sub_seq(string str)
{
    vector<string> arr;

    sub_seq_aux(str, "", 0, arr);

    for (auto str : arr)
        cout << str << endl;
}