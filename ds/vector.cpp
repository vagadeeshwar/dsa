// Write a program in C++ to handle the following task using vector
// Insert n numbers in the vector
// Print n numbers in the vector
// Swap two numbers
// Sort the n numbers in the vector
// Reverse the previously sorted numbers
//  Delete 2 numbers from the vector
// i.One number from the beginning
// ii.Another from the last
// iii.Display the remaining numbers in the vector

#include <iostream>
#include <vector>

using namespace std;

void accept(vector<int> &v, int &n)
{
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }
}

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void swap(vector<int> &v, const int &index1, const int &index2)
{
    int temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp;
}

int main()
{
    vector<int> v;
    vector<int>::iterator it = v.begin();
    int choice, n;
    while (choice != -1)
    {
        cout << "Enter your choice:\n-1.Exit\n1.Insert\n2.Swap\n3.Sortasc4.Sortdesc\n5.Delete from start and back 1 element\n6.Display\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> n;
            accept(v, n);
            break;
        case 2:
            swap(v, 0, 1);
            break;
        case 3:
            sort(v.begin(), v.end()); // ascending
            break;
        case 4:
            sort(v.begin(), v.end(), greater<int>()); // descending
            break;
        case 5:
            v.pop_back();
            v.erase(it);
            break;
        case 6:
            print(v);
            break;
        default:;
        }
    }

    return 0;
}