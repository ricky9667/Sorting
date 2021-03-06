#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(int *a, int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && key < a[i])
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
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

    insertion_sort(arr, n);
    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}