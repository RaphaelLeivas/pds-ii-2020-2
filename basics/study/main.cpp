#include<bits/stdc++.h>
#include "User.hpp"

using namespace std;

int main() {
    int num;
    string str;

    cout << "Write your name and age." << endl;
    cin >> num >> str;

    User* person1 = new User(num, str);

    cout << person1->getName() << person1->age << endl;
    cout << "Am I a teen? " << person1->isTeenager() << endl;

    delete person1;

    return 0;
}