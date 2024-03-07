#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

class act
{
public:
    string name;
    int start, finish;
    act(string name, int start, int finish)
    {
        this->name = name;
        this->start = start;
        this->finish = finish;
    }
};

bool compare(act &obj1, act &obj2)
{
    if (obj1.start > obj2.start)
        return true;
    else
        return false;
}

vector<string> asp_recur_aux(vector<act> &arr, int i, int prev, vector<string> &list)
{
    if (i == arr.size())
        return list;

    if (arr[i].finish <= arr[prev].start)
    {
        list.insert(list.begin(), arr[i].name);
        return asp_recur_aux(arr, i + 1, i, list);
    }
    else
        return asp_recur_aux(arr, i + 1, prev, list);
}

vector<string> asp_recur(vector<act> &arr)
{
    vector<string> list;
    sort(arr.begin(), arr.end(), compare);
    list.push_back(arr[0].name);
    return asp_recur_aux(arr, 1, 0, list);
}

vector<string> asp(vector<act> &arr)
{
    vector<string> list;
    int n = arr.size();

    sort(arr.begin(), arr.end(), compare);
    list.push_back(arr[0].name);

    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].finish <= arr[prev].start)
        {
            list.insert(list.begin(), arr[i].name);
            prev = i;
        }
    }
    return list;
}

int main()
{
    int n, start, finish;
    string name;
    cin >> n;

    vector<act> arr;

    for (auto i = 0; i < n; i++)
    {
        cin >> name >> start >> finish;
        arr.push_back(act(name, start, finish));
    }

    vector<string> list = asp(arr);

    for (auto x : list)
        cout << x << " ";
    cout << endl;

    return 0;
}