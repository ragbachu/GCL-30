#include<bits/stdc++.h>
using namespace std;

void change_a_call_by_value(int a) {
    a = 5;
}

void change_a_call_by_reference(int &a) {
    a = 5;
}

int main() {

    int a = 10;

    cout << "Value of a before calling change_a_call_by_value(): " << a << endl;
    
    // Call by value
    change_a_call_by_value(a);

    cout << "Value of a after calling change_a_call_by_value(): " << a << endl;

    cout << endl;

    cout << "Value of a before calling change_a_call_by_reference(): " << a << endl;

    change_a_call_by_reference(a);

    cout << "Value of a after calling change_a_call_by_reference(): " << a << endl;
}
