#include <iostream>
#include <vector>

// n^2,n^2

using namespace std;

void selec_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    for (vector<float>::iterator it = begin; it != end - 1; it++)
        swap(*min_element(it, end), *it);
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

    selec_sort(begin, end); // begin, end must be variables (not literals)

    for (float x : v)
        cout << x << endl;

    return 0;
}