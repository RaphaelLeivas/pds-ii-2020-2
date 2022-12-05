#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>

using namespace std;

class User {
    public: 
        int age;
        string name;

        User(int x, string str);  // construtor
        string getName();
        bool isTeenager();
};

#endif