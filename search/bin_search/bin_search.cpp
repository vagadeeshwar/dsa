#include <iostream>
#include <vector>

// 1,lgn

using namespace std;

int bin_search(vector<float>::iterator &begin, vector<float>::iterator &end, float &item)
{
    static vector<float>::iterator beg_arr = begin; // to remember start of array as it's lost due to recursive calls
    if (distance(begin, end) == 0)
        return -1;
    vector<float>::iterator mid = begin + distance(begin, end) / 2;

    if (*mid == item)
        return distance(beg_arr, mid);
    else if (item > *mid)
    {
        ++mid; // as we are using call by reference we can only pass variables and not literals
        return bin_search(mid, end, item);
    }
    else
        return bin_search(begin, mid, item);
}

int main()
{
    int n;
    float item;

    cout << "Enter the length of the vector: ";
    cin >> n;
    vector<float> v(n, 0);

    cout << "Enter the elements in sorted order: ";
    for (float &x : v)
        cin >> x;

    cout << "Enter the item to search for: ";
    cin >> item;

    vector<float>::iterator begin = v.begin(), end = v.end();

    cout << bin_search(begin, end, item) << endl;

    return 0;
}