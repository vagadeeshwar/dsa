#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int dp[100][100]; // mem for top down

int count_parens(int n);
int matrixChainMemoised(int *p, int i, int j); // top down code
int MatrixChainOrder(int *p, int n);

void print_parens(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_parens(s, i, s[i - 1][j - 1]);
        print_parens(s, s[i - 1][j - 1] + 1, j);
        cout << ")";
    }
}

int mcm_bu(vector<int> &p)
{
    int n = p.size() - 1, l, i, j, k, q; // price array, mtable for minimum, stable for tracing parenthesization
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    // try length of chain from 2 to n
    for (l = 2; l <= n; l++)
    {
        // From where does the chain starts is in 'i'
        // cout<<"l is "<<l<<endl;
        for (i = 1; i <= n - l + 1; i++)
        {
            // till what position does the chain goes is in 'j'
            j = i + l - 1;
            // cout<<"i is "<<i<<" j is "<<j;
            m[i - 1][j - 1] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // cout<< " k is "<<k<<endl;
                q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
                if (q < m[i - 1][j - 1])
                {
                    m[i - 1][j - 1] = q;
                    s[i - 1][j - 1] = k;
                }
            }
        }
    }
    print_parens(s, 1, n);
    return m[0][n - 1];
}

int main()
{
    int n, i, j;
    cin >> n;
    vector<int> price(n);

    for (i = 0; i < n; i++)
        cin >> price[i];

    cout << mcm_bu(price) << endl;

    return 0;
}

// Function for matrix chain multiplication
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int *p, int n)
{
    memset(dp, -1, sizeof dp);
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

// Driver Code for top down
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << MatrixChainOrder(arr, n);
//     return 0;
// }

int count_parens(int n) // catalan numbers
{
    static vector<int> arr = {1, 1};
    if (arr.size() >= n)
        return arr[n - 1];
    int q = 0;
    for (int i = 1; i <= n - 1; i++)
        q += count_parens(i) * count_parens(n - i);

    arr.push_back(q);
    return q;
}
