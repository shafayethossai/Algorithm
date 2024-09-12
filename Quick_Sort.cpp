#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pvot(vector<int>& arr, int low, int high) { // 10, 7, 8, 9, 1, 5
    int pivot = arr[high];
    int pointer = low;

    for (int i = low; i <= high-1; i++) {
        if (arr[i] < pivot) {
            swap(arr[pointer], arr[i]);
            pointer++;
        }
    }

    swap(arr[pointer], arr[high]);
    return pointer;
}

void quickSort(vector<int>& arr, int low, int high, int n) {
    //cout << "( " << low << ", " << high << " ) : ";
    print(arr, n);

    if (low < high) {
        int pi = pvot (arr, low, high);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}


int main () {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1, n);
    print(arr, n);

    return 0;
}
