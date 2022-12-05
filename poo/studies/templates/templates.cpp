#include <iostream>
#include <string>
#include "MyArray.cpp"

using namespace std;

struct person {
    string name;
    int age;

    struct person operator + (const struct person& obj) {
        struct person ans;
        ans.age = this->age + obj.age;
        ans.name = this->name + obj.name;

        return ans;
    };

    bool operator == (const struct person& obj) {
        bool ans1 = false, ans2 = false;

        if(this->age == obj.age) ans1 = true;
        if(this->name == obj.name) ans2 = true;

        return ans1 && ans2;
    };

    bool operator > (const struct person& obj) {
        bool ans = false;
        if(this->age == obj.age) ans = true;

        return ans;
   };
};

int main(void) {
    MyArray<int, 10> vec;

    for(int i = 0; i < 12; ++i) {
        vec.setValue(i, i*5);
    }

    cout << vec.getValue(5) << endl;

    return 0;
}