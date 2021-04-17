#include <bits/stdc++.h>
using namespace std;

int floorBS(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    if (x >= arr[high])
        return high;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
        return mid - 1;
    if (x < arr[mid])
        return floorBS(arr, low, mid - 1, x);
    return floorBS(arr, mid + 1, high, x);
}

int main()
{
    int arr[7];
    arr[0] = rand() % 10;
    for (int i = 1; i < 7; i++)
    {
        arr[i] = arr[i - 1] + ((rand() % 10) + 1);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = arr[0] + (rand() % (arr[6] - arr[0]));
    int index = floorBS(arr, 0, n - 1, x);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    if (index == -1)
        cout << "Floor of " << x << " doesn't exist in array";
    else
        cout << "Floor of " << x << " is " << arr[index];
    return 0;
}
