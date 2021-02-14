#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n(nums.size());
        vector<int> res(n);

        int l{0}, r = n -1,item{0};
        n--;
        while (l <= r) {
            item = (abs(nums[l]) > abs(nums[r])) ? nums[l++] : nums[r--];
            res[n--] = pow(item,2);
        }
        return res;
    }
    void print(vector<int> v) {
        for (auto i: v)
            cout << i << " ";
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};
    sol.print(sol.sortedSquares(nums));
}