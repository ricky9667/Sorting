#include <iostream>
using namespace std;

void quick_sort(int *a, int n)
{
    if (n <= 1)
        return;

    int l = 1, r = n - 1, temp;
    while (true)
    {
        while (a[l] <= a[0] && l < r)
            l++;
        while (a[r] >= a[0] && l < r)
            r--;
        if (l == r)
            break;
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;
    }

    // l == r == pivot
    temp = a[l];
    a[l] = a[0];
    a[0] = temp;

    quick_sort(a, l - 1);
    quick_sort(a + (l + 1), n - l);
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