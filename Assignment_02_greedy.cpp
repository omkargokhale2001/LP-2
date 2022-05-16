#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Sort
{

public:
    int n;
    int arr[100];

    void take_input()
    {
        cout << "Enter the number of elements in the array:" << endl;
        cin >> this->n;
        int i;
        for (i = 0; i < this->n; i++)
        {
            int element;
            cout << "Enter the " << i << "th element:" << endl;
            cin >> element;
            arr[i] = element;
        }
    }

    void selection_sort()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            int mini = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
    }

    void display()
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Sort s;
    s.take_input();
    s.display();
    s.selection_sort();
    s.display();

    return 0;
}