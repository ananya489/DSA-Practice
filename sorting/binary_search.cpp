#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}