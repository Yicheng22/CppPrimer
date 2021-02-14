#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l(0),r(height.size() - 1), maxArea(0), small(0);
        while (l < r) {
            small = height[l] > height[r] ? height[r--] : height[l++];
            maxArea = max(maxArea, (r - l + 1)*small);
        }
        return maxArea;
    }
};


int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(height);
    return 0;
}