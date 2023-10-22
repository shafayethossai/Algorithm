#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t; cin>>t;

    for(int i=1; i<=t; i++){
    string s,s2;
    cin>>s>>s2;
    int cnt = 0;
    size_t index = 0;

    while((index = s.find(s2, index)) != string::npos){
        cnt++;
        index++;
    }
    cout<<"Case "<<i<<": "<<cnt<<endl;
}


    return 0;
}
