#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Auxiliary space: O(1)
// Space complexity: O(n)

int smallest_positive_missing(vector<int> arr) {

    int n = arr.size();

    // Replacing the elements outside the range [1, n] with (n + 1).
    for (int i = 0; i < n; i++) {
        if (arr[i] < 1 or arr[i] > n) {
            arr[i] = n + 1;
        }
    }

    // Making the buckets negative as we encounter the elements.
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) != n + 1 and arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] *= -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return (i + 1);
        }
    }

    // If all elements in range [1, n] occur in the array.
    return (n + 1);
}

int main() {

    cout << smallest_positive_missing({1, 2, 3, 4, 5}) << endl;
    cout << smallest_positive_missing({0, -10, 1, 3, -20}) << endl;
    cout << smallest_positive_missing({1, 2, 3, 1, 5}) << endl;
    cout << smallest_positive_missing({0, 0, 0, 0}) << endl;
}