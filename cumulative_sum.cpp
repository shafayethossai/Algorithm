#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int arr[n+3];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int pre[n+3];
    pre[0] = arr[0];

    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1] + arr[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == 0) {
            cout << pre[r] << endl;
        }
        else {
            cout << pre[r] - pre[l-1] << endl;
        }
    }
    return 0;
}
