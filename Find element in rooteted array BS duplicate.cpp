#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

bool binary_search(vector<ll>&v, ll n, ll tar) {
    ll l = 0, r = n-1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (v[mid] == tar) {
            return true;
        }
        if (v[l] == v[mid] && v[mid] == v[r]) {
            l++, r--;
            continue;
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
    return false;
}

int main() {
    fast;
    ll n, tar;
    cin >> n >> tar;
    vector<ll> v(n);

    for (auto &it: v) {
        cin >> it;
    }
    if (!binary_search(v, n, tar)) {
        cout << "Target not exist" << endl;
    }
    else {
        cout << "Target is exist" << endl;
    }

    return 0;
}
