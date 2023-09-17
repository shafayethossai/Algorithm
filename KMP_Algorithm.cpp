// O(m+n)
// find how many times pattern exist in text
// the task is to print the indexes of all the occurences of pattern string in the text string.for printing,starting index of a string should be taken as 1.

#include <bits/stdc++.h>
using namespace std;

void search (string pat, string txt) {
    vector <int> lps(pat.size(), 0);

    for (int i = 1; i < pat.size(); i++) {
        int j = lps[i-1];

        while (j > 0 && pat[j] != pat[i]) {
            j = lps[j-1];
        }

        if (pat[j] == pat[i])j++;

        lps[i] = j;
    }

    int m = pat.size();
    int n = txt.size();
    int i = 0, j = 0, cnt = 0;
    vector <int> ans;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cnt++;
            ans.push_back(i-(m-1)); // 3 - (-2) = 1
            j = lps[j-1];
        }
        else if (pat[j] != txt[i]) {
            if (j == 0)i++;
            j = lps[j-1];
        }
    }

    cout << "cnt : " << cnt << endl;

    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

int main () {
    string txt, pat;
    cin >> txt >> pat;
    search(pat, txt);

    return 0;
}
