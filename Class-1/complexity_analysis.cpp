#include<bits/stdc++.h>
using namespace std;

int main() {

    // ------------------------------------------------------------
    // size(arr1) = n
    // size(arr2) = m
    // Time complexity: O(n + m)

    for (int a: arr1) {
        cout << a << endl;
    }
    for (int b: arr2) {
        cout << b << endl;
    }
    // ------------------------------------------------------------
    // size(arr1) = n
    // size(arr2) = m
    // Time complexity: O(n * m)

    for (int a: arr1) {
        for (int b: arr2) {
            cout << a + b << endl;
        }
    }
    // ------------------------------------------------------------
    // size(arr) = n
    // Time complexity: O(n^2)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << arr[i] + arr[j] << endl;
        }
    }
    // ------------------------------------------------------------
    // size(arr) = n
    // Time complexity: O(n^2)

    /*
        In case when the code has some if-else conditions, then we must always consider the
        worst-case out of all those conditions.
    */

    for (int i = 0; i < n; i++) {

        if (arr[i] % 2 == 1) { // if arr[i] is an odd number
            for (int j = i + 1; j < n; j++) {
                cout << arr[i] + arr[j] << endl;
            }
        }
        else {
            cout << arr[i] << endl;
        }
    }
    // ------------------------------------------------------------
    // Time complexity: O(n * length(s))

    void func(string s, int n) {
        for (int i = 0; i < n; i++) {
            cout << s << endl;
        }
    }
    // ------------------------------------------------------------
    // Time complexity: O(2^n)

    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
    // ------------------------------------------------------------
    // Length(s) = m
    // Time complexity: O(n * m)
    // Auxiliary space complexity (assuming no tail recurisve optimization): O(n * m) (If string(s) is passed by value)
    
    void func(string s, int n) {
        if (n == 0) return;

        cout << s << endl;
        func(s, n - 1);
    }
    // ------------------------------------------------------------
    // Length(s) = m
    // Time complexity: O(n * m)
    // Auxiliary space complexity (assuming no tail recurisve optimization): O(n + m)

    void func(string &s, int n) {
        if (n == 0) return;

        cout << s << endl;
        func(s, n - 1);
    }


}