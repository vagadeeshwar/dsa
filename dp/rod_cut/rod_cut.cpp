#include <iostream>
#include <vector>
#include <algorithm>

// O(n^2)

using namespace std;

int rod_cut_td(vector<int> &price);
void print_rod_cut(vector<int> &s);

int rod_cut(vector<int> &price)
{
    int i, q, j, n = price.size();
    vector<int> r(n + 1, 0), s(n + 1, 0); // r stores max revenue, s stores cut positions

    for (j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (i = 1; i <= j; i++)
            if (q < price[i - 1] + r[j - i])
            {
                q = price[i - 1] + r[j - i];
                s[j] = i;
            }

        r[j] = q;
    }
    print_rod_cut(s);
    return r[n];
}

int main()
{
    int n;

    // cout << "Enter the length of the cut: ";
    cin >> n;
    vector<int> price(n, 0);

    // cout << "Enter the prices starting from rod of length 1: ";
    for (int &x : price)
        cin >> x;

    // vector<int> price{5, 7, 12, 23};

    // cout << rod_cut_td(price) << endl;
    cout << rod_cut(price) << endl;

    return 0;
}

void print_rod_cut(vector<int> &s)
{
    int n = s.size() - 1;
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
}

int rod_cut_aux(vector<int> &price, int n, vector<int> &dp)
{
    if (dp[n - 1] != -1)
        return dp[n - 1];

    int q = INT_MIN;
    for (int i = 1; i < n; i++)
        q = max(q, max(price[n - 1], rod_cut_aux(price, i, dp) + rod_cut_aux(price, n - i, dp)));
    return dp[n - 1] = q;
}

int rod_cut_td(vector<int> &price)
{
    int n = price.size();
    vector<int> dp(n, -1);
    dp[0] = price[0];
    return rod_cut_aux(price, n, dp);
}
