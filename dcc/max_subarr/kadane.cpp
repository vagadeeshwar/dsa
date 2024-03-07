#include <limits.h>
#include <iostream>
#include <vector>

// Greedy O(n)
using namespace std;

class MaxSubArray
{
public:
    int l;
    int h;
    int sum;

    MaxSubArray()
    {
        l = INT_MIN;
        h = INT_MIN;
        sum = 0;
    }

    MaxSubArray(int l, int h, int sum)
    {
        this->l = l;
        this->h = h;
        this->sum = sum;
    }
};

MaxSubArray maxSubArraySum(vector<int> &nums)
{
    int sum = 0, maxi = INT_MIN, l = 0, h = 0, s = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (maxi < sum)
        {
            maxi = sum;
            h = i;
            // l = s;
        }

        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
    }
    return MaxSubArray(s, h, maxi);
}

int main()
{
    int n, t;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
    MaxSubArray obj = maxSubArraySum(arr);
    cout << obj.l + 1 << endl
         << obj.h + 1 << endl
         << obj.sum << endl;

    return 0;
}