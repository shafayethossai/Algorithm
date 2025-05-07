#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubarraySum(vector<int> &arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        // Calculate maximum subarray sum ending at current position
        max_current = max(arr[i], max_current + arr[i]);

        // Update global maximum if current maximum is greater
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr);
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}
