#include <iostream>
#include <vector>

using namespace std;

void ins_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    for (auto it = begin + 1; it != end; it++)
    {
        // Searching the upper bound, i.e., first
        // element greater than *it from beginning
        auto const ins_point = upper_bound(begin, it, *it);

        // Shifting the unsorted part
        rotate(ins_point, it, it + 1);
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
