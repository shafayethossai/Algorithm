#include <bits/stdc++.h>
using namespace std;

int main () {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        int arr[n+4];

        for (int i=1; i<=n; i++) {
            cin >> arr[i];
        }
        int sum = 0;

        for (int i=1; i<=n; i++) {
            sum += i*(n-i+1) * arr[i];
        }
        cout << sum << endl;
    }

    return 0;
}
