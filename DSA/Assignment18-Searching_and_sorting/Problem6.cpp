// Time Complexity : O(nlogn)
// Space Complexity : O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    // Sort the balloons based on their end position
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int arrows = 1;  // Number of arrows needed
    int end = points[0][1];  // End position of the first balloon

    // Iterate through the sorted balloons
    for (int i = 1; i < points.size(); i++) {
        // If the current balloon starts after the previous balloon ends,
        // we need an additional arrow
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

int main() {
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int minArrows = findMinArrowShots(points);

    cout << "Minimum number of arrows needed: " << minArrows << endl;

    return 0;
}
