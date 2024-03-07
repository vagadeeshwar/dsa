#include <iostream>
#include <vector>

// nlgn,nlgn

using namespace std;

// call by reference musn't be used as we are manipulating begin inside and that will reflect in merge_sort begin
void merge(vector<float>::iterator begin, vector<float>::iterator mid, vector<float>::iterator end) // not done inplace
{
    vector<float> lv(begin, begin + distance(begin, mid)), rv(mid, mid + distance(mid, end)); // copying left and right vectors
    vector<float>::iterator itl = lv.begin(), itr = rv.begin();

    while (itl != lv.end() && itr != rv.end())
    {
        if (*itl <= *itr)
        {
            *begin = *itl;
            begin++;
            itl++;
        }
        else
        {
            *begin = *itr;
            begin++;
            itr++;
        }
    }
    if (itl != lv.end())
    {
        for (; itl != lv.end(); itl++)
        {
            *begin = *itl;
            begin++;
        }
    }
    else
    {
        for (; itr != rv.end(); itr++)
        {
            *begin = *itr;
            begin++;
        }
    }
}

void merge_sort(vector<float>::iterator &begin, vector<float>::iterator &end)
{
    if (distance(begin, end) == 1)
        return;
    vector<float>::iterator mid = begin + distance(begin, end) / 2;

    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
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

    merge_sort(begin, end); // begin, end must be variables (not literals)

    for (float x : v)
        cout << x << endl;

    return 0;
}