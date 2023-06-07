#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();

    if (n < 2) {
        return true;
    }

    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];

    double referenceSlope = (double)(y2 - y1) / (x2 - x1);

    for (int i = 2; i < n; i++) {
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];

        double currentSlope = (double)(yi - y1) / (xi - x1);

        if (currentSlope != referenceSlope) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    bool isStraightLine = checkStraightLine(coordinates);
    cout << (isStraightLine ? "true" : "false") << endl;
    return 0;
}
