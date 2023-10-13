#include <bits/stdc++.h>
using namespace std;

int solve (int arr[], int l, int r) {
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid < r && arr[mid + 1] < arr[mid]) {
            ans = mid + 1;
            break;
        }
        else if (mid > l && arr[mid] < arr[mid-1]) {
            ans = mid;
            break;
        }
        if (arr[r] > arr[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
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

    cout << "Answer is : " << solve (arr, 0, n-1) << endl;

    return 0;
}
