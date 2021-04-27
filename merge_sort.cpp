#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int *arr, int n)
{
    cout << "DEBUG n = " << n << endl;
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";

    if (n == 1)
        return;

    int r_size = n / 2;
    int l_size = n - r_size;
    // cout << "l_size = " << l_size << ", r_size = " << r_size << endl;

    // cout << "[Left Split]" << endl;
    int left[l_size];
    for (int p = 0; p < l_size; p++)
    {
        left[p] = arr[p];
        // cout << p << " " << left[p] << endl;
    }
    merge_sort(left, l_size);

    // cout << "[Right Split]" << endl;
    int right[r_size];
    for (int p = 0; p < r_size; p++)
    {
        right[p] = arr[p + l_size];
        // cout << p + l_size << " " << right[p] << endl;
    }
    merge_sort(right, r_size);

    int i = 0, j = 0;
    while (i < l_size || j < r_size)
    {
        if (j >= r_size || left[i] <= right[j])
        {
            arr[i + j] = left[i];
            i++;
        }
        if (i >= l_size || left[i] > right[j])
        {
            arr[i + j] = right[j];
            j++;
        }
    }

    cout << "DEBUG n = " << n << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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

    merge_sort(arr, n);

    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}