#include <iostream>
#include <vector>

// n,n^2

using namespace std;

void bubble_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    bool already_sorted;
    for (int i = 0; i != distance(begin, end) - 1; i++)
    {
        already_sorted = true;
        for (vector<float>::iterator it = begin; it != end - i - 1; it++)
            if (*it > *(it + 1))
            {
                // float temp = *it;
                // *it = *(it + 1);
                // *(it + 1) = temp;
                swap(*it, *(it + 1));
                already_sorted = false;
            }
        if (already_sorted)
            break;
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

    bubble_sort(begin, end); // begin, end must be variables (not literals)

    for (float x : v)
        cout << x << endl;

    return 0;
}