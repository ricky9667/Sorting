#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int *arr, int n)
{
    if (n == 1)
        return;

    int r_size = n / 2;
    int l_size = n - r_size;

    int left[l_size];
    for (int p = 0; p < l_size; p++)
        left[p] = arr[p];
    merge_sort(left, l_size);

    int right[r_size];
    for (int p = 0; p < r_size; p++)
        right[p] = arr[p + l_size];
    merge_sort(right, r_size);

    int i = 0, j = 0;
    while (i < l_size || j < r_size)
    {
        if (j >= r_size)
        {
            arr[i + j] = left[i];
            i++;
            continue;
        }
        if (i >= l_size)
        {
            arr[i + j] = right[j];
            j++;
            continue;
        }
        if (j >= r_size || left[i] <= right[j])
        {
            arr[i + j] = left[i];
            i++;
            continue;
        }
        if (i >= l_size || left[i] > right[j])
        {
            arr[i + j] = right[j];
            j++;
            continue;
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

    merge_sort(arr, n);

    cout << "After sorting: " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}