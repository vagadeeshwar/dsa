#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(float a, float b) // function passed to inplace_merge to alter comparison criterion, here used to implement descending sorting
{
    return a > b ? true : false;
}

void merge_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    if (distance(begin, end) == 1)
        return;
    vector<float>::iterator mid = begin + distance(begin, end) / 2;

    merge_sort(begin, mid);
    merge_sort(mid, end);
    inplace_merge(begin, mid, end, cmp); // cmp optional
}

int main()
{
    int n;

    cout << "Enter the length of the vector: ";
    cin >> n;
    vector<float> v(n, 0);

    cout << "Enter the elements: ";
    for (float &x : v)
    {
        cin >> x;
    }

    vector<float>::iterator begin = v.begin(), end = v.end();

    merge_sort(begin, end);

    for (auto x : v)
        cout << x << endl;

    return 0;
}
