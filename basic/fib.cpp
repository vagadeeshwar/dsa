#include <iostream>
#include <map>
#include <vector>

// O(n)

using namespace std;

int fib_td_aux(int n, map<int, int> &mem)
{
    if (mem.find(n) != mem.end())
        return mem[n];
    mem[n] = fib_td_aux(n - 1, mem) + fib_td_aux(n - 2, mem);
    return mem[n];
}

int fib_td(int n)
{
    map<int, int> mem{{2, 1}, {1, 0}};
    return fib_td_aux(n, mem);
}

int fib_bu(int n)
{
    vector<int> table{0, 1};
    for (int i = 0; i < n - 2; i++)
        table.push_back(table[i] + table[i + 1]);
    return table.back();
}

int main()
{
    int n;
    cin >> n;
    cout << fib_td(n) << endl;
    cout << fib_bu(n) << endl;
    return 0;
}