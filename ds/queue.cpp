//  a.Insert the element in the queue
//  b.Delete the element from the queue
//  c.Display queue
//  d.Fetch front element
//  e.Fetch last element
//  f.Quit

#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int choice, n;
    queue<int> q;

    while (choice != -1)
    {
        cout << "Enter your choice:\n-1.Exit\n1.Insert\n2.Delete\n3.Display\n4.Front\n5.Last\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> n;
            q.push(n);
            break;
        case 2:
            cout << "The deleted element is " << q.front() << endl;
            q.pop();
            break;
        case 3:
            print(q);
            break;
        case 4:
            cout << q.front() << endl;
            break;
        case 5:
            cout << q.back() << endl;
        default:
            break;
        }
    }

    return 0;
}