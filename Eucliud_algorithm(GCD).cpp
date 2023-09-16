//  O[logn]

#include <bits/stdc++.h>
using namespace std;

#define    ll   long long

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    else {
        return gcd (b, a%b);
    }
}

ll lcm (ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main () {
    int tc;
    cin >> tc;

    while (tc--) {
        int a, b;
        cin >> a >> b;

        cout << gcd(a, b) << endl;
        cout << lcm(a, b) << endl;

    }


    return 0;
}
