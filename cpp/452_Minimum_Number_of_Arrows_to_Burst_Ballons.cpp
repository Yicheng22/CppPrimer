#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if ( n < 2) return n;
        
        // lambda expression sort
        sort(points.begin(), points.end(), [](vector<int>& x, vector<int>& y) -> bool {
            return x[1] < y[1];
        });
        int total{n}, prev{points[0][1]};
        for (int i(1); i < n; i++) {
            if (points[i][0] <= prev) 
                total--;
            else
                prev = points[i][1];
        }
        return total;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};
    cout << sol.findMinArrowShots(points1) << endl;

    vector<vector<int>> points2 = {{1,2},{2,3},{3,4},{4,5}};
    cout << sol.findMinArrowShots(points2) << endl;
    return 0;
}