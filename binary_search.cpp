// O(log n)
#include <bits/stdc++.h>
using namespace std;


void Binary_search(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;

    while (l <= r) {
        int mid = (l+r) / 2;
        if (arr[mid] == x) {
            cout << "Found" << endl;
            cout << "In index : " << mid << endl;
            return;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << "It is not exist" << endl;
}

signed main(){
    int n;
    cin >> n;
    int arr[n+3];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    Binary_search(arr, n, x);

    return 0;
}
