#include <bits/stdc++.h>
using namespace std;

ll binary_search(vector<ll>&v, ll n, ll tar) {
    ll l = 0, r = n-1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (v[mid] == tar) {
            return mid;
        }
        // left half sorted
        else if (v[l] <= v[mid]) {
            if (v[l] <= tar && tar <= v[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        // right half sorted
        else {
            if (v[mid] <= tar && tar <= v[r]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    fast;
    ll n, tar;
    cin >> n >> tar;
    vector<ll> v(n);

    for (auto &it: v) {
        cin >> it;
    }
    if (binary_search(v, n, tar) == -1) {
        cout << "Target not exist" << endl;
    }
    else {
        cout << "Target is here : " << binary_search(v, n, tar) << endl;
    }

    return 0;
}
