#include <bits/stdc++.h>
using namespace std;

int FO (int arr[], int n, int x) {
    int ans = -1;
    int l = 0;
    int r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = mid;
            r = mid - 1;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}

int LO (int arr[], int n, int x) {
    int ans = -1;
    int l = 0;
    int r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = mid;
            l = mid + 1;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}

signed main () {
    int n;
    cin >> n;

    int arr[n+3];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int num_of_ele = LO (arr, n, x) - FO (arr, n, x) + 1;

    cout << "Count of an element in sorted array : " << num_of_ele << endl;

    return 0;
}
