#include <iostream>
using namespace std;

void max_heapify(int *arr, int n)
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
                k = arr[i] >= arr[i + 1] ? i : i + 1;
            else
                k = i;

            if (arr[k] > arr[i / 2])
            {
                int temp = arr[k];
                arr[k] = arr[i / 2];
                arr[i / 2] = temp;
            }
        }
        index >>= 1;
    }
}

void heap_sort(int *arr, int n)
{
    if (n <= 1)
        return;

    max_heapify(arr - 1, n);

    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;

    heap_sort(arr, n - 1);
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
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