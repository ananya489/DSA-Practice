#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Comparator to sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    int n = activities.size();

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";

    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinish = activities[i].finish;
        }
    }
}

int main() {

    vector<Activity> activities = {
        {1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}
    };

    activitySelection(activities);

    return 0;
}