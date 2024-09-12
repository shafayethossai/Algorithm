// O(m+n)
// find how many times pattern exist in text
// the task is to print the indexes of all the occurences of pattern string in the text string.for printing,starting index of a string should be taken as 1.

#include <bits/stdc++.h>
using namespace std;

void search(string pat, string txt) {
    vector<int> lps(pat.size(), 0);

    // Preprocess the pattern (calculate LPS array)
    for (int i = 1; i < pat.size(); i++) {
        int j = lps[i - 1];

        while (j > 0 && pat[j] != pat[i]) {
            j = lps[j - 1];
        }

        if (pat[j] == pat[i]) j++;

        lps[i] = j;
    }

    int m = pat.size();
    int n = txt.size();
    int i = 0, j = 0, cnt = 0;
    vector<int> ans;

    // Traverse the text and search for the pattern
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cnt++;
            ans.push_back(i - m + 1);  // Corrected index for 1-based result
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }

    cout << "Count: " << cnt << endl;

    for (auto it : ans) {
        cout << it << " ";  // Printing the 1-based starting index
    }
    cout << endl;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    search(pat, txt);

    return 0;
}
