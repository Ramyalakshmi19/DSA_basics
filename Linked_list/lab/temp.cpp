#include <iostream>
#include <math.h>
using namespace std;
class queue
{
public:
    int *arr;
    int front;
    int back;

public:
    void number(int n)
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "no elements in queue" << endl;
            return;
        }
        cout << arr[front] << " ";
        front++;
    }
};
int main()
{
    int n;
    int sum = 0;
    cout << "ENTER THE NUMBER OF LEVELS: ";
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
    {
        sum = sum + 1;
    }
    queue q, q1;
    q.number(sum - 1);
    for (int i = 0; i < sum - 1; i++)
    {
        int k;
        cout << "Enter the value :";
        cin >> k;
        q.push(k);
    }
    q1 = q;
    cout << endl;
    int start, end;
    cout << "The given binary tree is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= pow(2, i); j++)
        {
            q1.pop();
        }
        cout << endl;
    }
    cout << "Enter the starting level: ";
    cin >> start;
    cout << "Enter the ending level: ";
    cin >> end;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 > start && i + 1 < end)
        {
            for (int j = pow(2, i); j < pow(2, i + 1); j++)
            {
                cout << q.arr[j - 1] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}