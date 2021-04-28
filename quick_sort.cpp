#include <iostream>
using namespace std;

void quick_sort(int *a, int n)
{
    if (n <= 1)
        return;
    // if (n == 2)
    // {
    //     if (a[0] > a[1])
    //     {
    //         int temp = a[0];
    //         a[0] = a[1];
    //         a[1] = temp;
    //     }
    //     return;
    // }

    // partition
    int i = -1, end = n - 1;
    for (int j = 0; j < n; j++)
    {
        if (a[j] <= a[end])
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // pivot = i
    quick_sort(a, i);
    quick_sort(a + (i + 1), n - i - 1);
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

    quick_sort(arr, n);
    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}