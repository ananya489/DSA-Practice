#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    int n = jobs.size();

    // Sort jobs by maximum profit
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto &job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> slot(maxDeadline, '-');

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == '-') {
                slot[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (char j : slot) {
        if (j != '-')
            cout << j << " ";
    }
}

int main() {

    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobScheduling(jobs);

    return 0;
}