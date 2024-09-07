// Merge Sort algorithm
// Time Complexity O(nlogn)
// Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

void merge_sort (int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    vector<int> L, R;

    for (int i = l; i <= mid; i++) {
        L.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        R.push_back(arr[i]);
    }

    int Lid = 0, Rid = 0, i = l; 

    while (Lid < L.size() || Rid < R.size()) {
        if (Rid == R.size() || (Lid < L.size() && L[Lid] < R[Rid])) {
            arr[i] = L[Lid];
            Lid++;
        } 
        else {
            arr[i] = R[Rid];
            Rid++;
        }
        i++; 
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    merge_sort(1, n);

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
