#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};

    sort(activities.begin(), activities.end(), compare);

    cout << "Selected Activities: \n";
    int lastFinish = -1;

    for (auto &act : activities) {
        if (act.start >= lastFinish) {
            cout << "(" << act.start << ", " << act.finish << ")\n";
            lastFinish = act.finish;
        }
    }
    return 0;
}
