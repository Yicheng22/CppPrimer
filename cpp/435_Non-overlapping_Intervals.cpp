#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;
        // lambda expression sort
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) -> bool {
            return x[1] < y[1];
        });
        int total{0}, prev{intervals[0][1]};
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                total++;
            } else {
                prev = intervals[i][1];
            }
        }  
        return total;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intervals;
    intervals.push_back({1,4});
    intervals.push_back({2,4});
    intervals.push_back({3,4});
    intervals.push_back({3,5});

    cout << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}