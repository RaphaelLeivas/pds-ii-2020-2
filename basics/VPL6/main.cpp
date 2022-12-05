#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    map<string, int> indices;
    string p;

    while(cin >> p){
        indices[p]++;
    }

    int sum = 0;
    for(map<string, int>::iterator it = indices.begin(); it != indices.end(); ++it){
        string s = it->first;
        sum += indices[s];
    }

    for(map<string, int>::iterator it = indices.begin(); it != indices.end(); ++it){
        string s = it->first;
        if(s.length() >= 3){
            cout << setprecision(2) << fixed << s << " " << indices[s] << " "
            << indices[s]/(float)sum << endl;
        }
    }
    return 0;
}