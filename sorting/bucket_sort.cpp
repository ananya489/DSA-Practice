#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[k++] = val;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<float> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << fixed << setprecision(2) << arr[i];
    }

    return 0;
}