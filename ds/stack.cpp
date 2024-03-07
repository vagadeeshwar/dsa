// A menu driven program in C++ to imple stack using STL that performs
// a.Insert the element in the stack
// b.Delete the element from the stack
// c.Display size of the stack
// d.Fetch top most element from the stack
// e.Quit

#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<int> s;
    int choice, n;
    while (choice != -1)
    {
        cout << "Enter your choice:\n-1.Exit\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> n;
            s.push(n);
            break;
        case 2:
            if (!s.empty())
            {
                cout << s.top() << " Popped\n";
                s.pop();
            }
            else
                cout << "Stack empty, Can't pop\n";
            break;
        case 3:
            cout << s.size() << endl;
            break;
        case 4:
            cout << s.top() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}