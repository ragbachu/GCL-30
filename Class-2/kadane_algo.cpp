#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> arr) {

    int n = arr.size();
    int max_till_here = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        max_till_here = max(arr[i], max_till_here + arr[i]);
        result = max(result, max_till_here);
    }

    return result;
}

void print_max_sum_subarray(vector<int> arr) {

    int n = arr.size();
    int max_till_here = arr[0];
    int result = arr[0];

    int current_start = 0, end = 0, start = 0;

    for (int i = 1; i < n; i++) {

        max_till_here = max(arr[i], max_till_here + arr[i]);
        if (max_till_here > result) {
            start = current_start;
            end = i;
            result = max_till_here;
        }
        if (max_till_here < 0) {
            current_start = i + 1;
        }
    }

    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    cout << max_subarray_sum({2, -3, 1, 4, 7, -1}) << endl;
    cout << max_subarray_sum({4, -3, 1, 4, 7, -1}) << endl;
    cout << max_subarray_sum({-4, -3, -1, -4, -7, -1}) << endl;

    print_max_sum_subarray({2, -3, 1, 4, 7, -1});
    print_max_sum_subarray({4, -3, 1, 4, 7, -1});
    print_max_sum_subarray({-4, -3, -1, -4, -7, -1});
    print_max_sum_subarray({1, 2, -10, -20});
}
