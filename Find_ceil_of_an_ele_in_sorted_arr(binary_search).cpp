#include <bits/stdc++.h>
using namespace std;

int Ceil (int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = arr[mid];
            break;
        }
        else if (arr[mid] > x) {
            ans = arr[mid];
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

    int x;
    cin >> x;

    cout << "Answer is : " << Ceil(arr, n, x) << endl;

    return 0;
}
