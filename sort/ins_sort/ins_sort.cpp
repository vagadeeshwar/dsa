#include <iostream>
#include <vector>

// n,n^2

using namespace std;

void ins_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    int n = distance(begin, end);
    float key;
    vector<float>::iterator it;

    for (int i = 1; i < n; i++)
    {
        key = *(begin + i);
        it = begin + i - 1;

        while (it >= begin && *it > key)
        {
            *(it + 1) = *it;
            it--;
        }
        *(it + 1) = key;
    }
}

int main()
{
    int n;

    cout << "Enter the length of the vector: ";
    cin >> n;
    vector<float> v(n, 0);

    cout << "Enter the elements: ";
    for (float &x : v)
        cin >> x;

    vector<float>::iterator begin = v.begin(), end = v.end();

    ins_sort(begin, end); // begin, end must be variables (not literals)

    for (float x : v)
        cout << x << endl;

    return 0;
}