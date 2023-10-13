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

bool Binary_search (int arr[], int l, int n, int x) {
    int r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == x) {
            return true;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    int arr[n+3];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int first_ele = solve(arr, 0, n-1);
    //cout << first_ele << endl;

    int x;
    cin >> x;

    bool result1 = Binary_search(arr, 0, first_ele-1, x);
    bool result2 = Binary_search(arr, first_ele, n-1, x);

    if (result1 == true || result2 == true) {
        cout << "It is exist" << endl;
    }
    else {
        cout << "It is not exist" << endl;
    }

    return 0;
}
