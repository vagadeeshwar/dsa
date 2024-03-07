#include <iostream>
#include <vector>

// 1,n/2

using namespace std;

int linear_search(vector<float>::iterator &begin, vector<float>::iterator &end, float &item)
{
    for (vector<float>::iterator it = begin; it != end; it++)
        if (*it == item)
            return distance(begin, it);
    return -1;
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

    cout << linear_search(begin, end, item) << endl;

    return 0;
}