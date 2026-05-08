#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int count = 0;
        string repeated = word;

        // Keep checking repeated occurrences
        while (sequence.find(repeated) != string::npos) {
            count++;
            repeated += word;
        }

        return count;
    }
};

int main() {

    Solution obj;

    string sequence = "ababc";
    string word = "ab";

    int ans = obj.maxRepeating(sequence, word);

    cout << "Maximum Repeating Count: " << ans << endl;

    return 0;
}