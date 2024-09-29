#include <bits/stdc++.h>
using namespace std;

void jobSequencing(int numTasks, vector<int>& days, vector<int>& earnings) {
    vector<pair<int, int>> tasks(numTasks);
    for (int i = 0; i < numTasks; i++) {
        tasks[i] = {earnings[i], days[i]};
    }

    sort(tasks.rbegin(), tasks.rend());

    vector<int> ans(numTasks + 1, -1);
    vector<bool> occupied(numTasks + 1, false);

    for (int i = 0; i < numTasks; i++) {
        int earning = tasks[i].first;
        int day = tasks[i].second;

        for (int j = min(numTasks, day); j > 0; j--) {
            if (!occupied[j]) {
                occupied[j] = true;
                ans[j] = i;
                break;
            }
        }
    }

    for (int i = 1; i <= numTasks; i++) {
        cout << (ans[i] != -1 ? tasks[ans[i]].first : -1) << " ";
    }
    cout << endl;
}

int main() {
    int numTasks;
    cin >> numTasks;

    vector<int> days(numTasks);
    vector<int> earnings(numTasks);

    for (int i = 0; i < numTasks; i++) {
        cin >> days[i] >> earnings[i];
    }

    jobSequencing(numTasks, days, earnings);
    
    return 0;
}
