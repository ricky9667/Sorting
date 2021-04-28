#include <iostream>
using namespace std;

void shell_sort(int *a, int n)
{
    for (int k = n / 2; k; k /= 2)
    {
        for (int i = 0; i + k < n; i++)
        {
            int p = i;
            while (p >= 0 && a[p] > a[p + k])
            {
                int temp = a[p];
                a[p] = a[p + k];
                a[p + k] = temp;
                p -= k;
            }
        }
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

    shell_sort(arr, n);
    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}