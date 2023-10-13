#include <bits/stdc++.h>
using namespace std;

int NS (int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = mid;
            break;
        }
        else if (l <= mid && arr[mid-1] == x) {
            ans = mid -1;
            break;
        }
        else if (r >= mid && arr[mid+1] == x) {
            ans = mid + 1;
            break;
        }
        if (arr[mid] > x) {
            r = mid - 2;
        }
        else {
            l = mid + 2;
        }
    }

    return ans;
}

int main () {
    int n;
    cin >> n;
    int arr[n+3];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    cout << "Answer is : " << NS(arr, n, x) << endl;


    return 0;
}
