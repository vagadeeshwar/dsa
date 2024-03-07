#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool cmp(float a, float b) // not sure how to use this function
// {
// }

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

    cout << (binary_search(v.begin(), v.end(), item) ? "true" : "false") << endl; //returns only bool, not index

    return 0;
}