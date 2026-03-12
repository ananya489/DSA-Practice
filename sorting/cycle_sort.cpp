#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int>& arr) {
    int n = arr.size();

    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;

        // Find correct position of the item
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item)
                pos++;
        }

        // If item already in correct position
        if (pos == cycle_start)
            continue;

        // Skip duplicates
        while (item == arr[pos])
            pos++;

        // Put item to its right position
        if (pos != cycle_start)
            swap(item, arr[pos]);

        // Rotate rest of cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            while (item == arr[pos])
                pos++;

            if (item != arr[pos])
                swap(item, arr[pos]);
        }
    }
}

int main() {
    vector<int> arr = {4, 3, 2, 1, 5};

    cycleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}