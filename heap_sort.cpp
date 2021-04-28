#include <iostream>
using namespace std;

void max_heapify(int *a, int n)
{
    int index = 2;
    while (index * 2 <= n)
        index *= 2;

    while (index > 1)
    {
        for (int i = index; i <= n; i += 2)
        {
            int k;
            if (i + 1 <= n)
                k = a[i] >= a[i + 1] ? i : i + 1;
            else
                k = i;

            if (a[k] > a[i / 2])
            {
                int temp = a[k];
                a[k] = a[i / 2];
                a[i / 2] = temp;
            }
        }
        index >>= 1;
    }
}

void heap_sort(int *a, int n)
{
    if (n <= 1)
        return;

    max_heapify(a - 1, n);

    int temp = a[0];
    a[0] = a[n - 1];
    a[n - 1] = temp;

    heap_sort(a, n - 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    int arr[1000001];

    cout << "Input n: ";
    cin >> n;

    cout << "Input numbers: " << endl;
    for (int i = 0, temp; i < n; i++)
        cin >> arr[i];

    heap_sort(arr, n);
    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}