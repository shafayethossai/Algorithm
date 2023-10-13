#include <bits/stdc++.h>
using namespace std;

char solve (string s, char ch, int n) {
    int l = 0;
    int r = n-1;
    char ans;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (s[mid] > ch) {
            ans = s[mid];
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;
}

int main () {
    string s;
    char ch;
    cin >> s >> ch;

    cout << "next alphabetical element : " << solve (s, ch, s.size()) << endl;

    return 0;
}
