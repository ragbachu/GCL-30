#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n * m)
Aux space: O(1)
Space complexity: O(n * m)
*/

vector<vector<bool>> set_boolean_matrix_zero(vector<vector<bool>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    bool first_row = false, first_col = false;

    // Initializing the row flag and the column flag to check whether the first row
    // and the first column originally contains any zero.
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            first_row = true;
            break;
        }
    }
    for (int i =0; i < n; i++) {
        if (arr[i][0] == 0) {
            first_col = true;
            break;
        }
    }

    // If we encounter any zero in the internal matrix, we set its row and column bucket to zero.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // Making the row bucket zero.
                arr[0][j] = 0; // Making the column bucket zero.
            }
        }
    }

    // For the internal matrix, if the row bucket or column bucket of any element is zero, then that
    // element will also be set to zero.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 or arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    // Checking the first_row and first_col flag and making the corresponding updates.
    if (first_row) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
    if (first_col) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }

    return arr;
}

int main() {

    vector<vector<bool>> res = set_boolean_matrix_zero({{1, 0, 1},
                                                        {1, 1, 1},
                                                        {1, 1, 1}});

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    res = set_boolean_matrix_zero({{1, 0, 1},
                                    {1, 1, 1},
                                    {1, 0, 1}});

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    res = set_boolean_matrix_zero({{1, 1, 1, 1},
                                    {0, 1, 0, 0},
                                    {1, 1, 1, 1},
                                    {0, 1, 1, 1},
                                    {1, 1, 1, 1}});

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
}