#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), profit(n);
    vector<double > ratio;

    for (int i=0; i<n; i++) {
        cin >> weight[i];
    }
    for (int i=0; i<n; i++) {
       cin >> profit[i];
    }
    for (int i=0; i<n; i++) {
      double x = (double)profit[i] / weight[i];
      ratio.push_back(x);
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    int sum=0, total_w=0;
    for (int i=0; i<n; i++) {
        if (weight[i] < w) {
            //cout << "less : profit : " << profit[i] << ", now_weight: " << total_w + weight[i] << "total weight: " << total_w << endl;
            sum += profit[i];
            w -= weight[i];
        }
        else {
           sum += w * ratio[i];
           w = 0;
        }
    }
    cout << sum << endl;

    return 0;
}
