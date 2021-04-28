#include <iostream>
using namespace std;

void quick_sort(int *a, int n)
{
    if (n <= 1)
        return;
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
    return 0;
}