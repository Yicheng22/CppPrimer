#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end())
                m[target - nums[i]] = i;
            else
                return {m[nums[i]],i};   
        }
        return {0,0};
    }

    void display_vector(const vector<int> &v)
    {
        copy(v.begin(), v.end(),
            ostream_iterator<int>(cout, " "));
    }
};

int main()
{
    Solution sol;
    int target(9);
    vector<int> nums={2,7,9,15};
    vector<int> res;
    res = sol.twoSum(nums, target);
    sol.display_vector(sol.twoSum(nums, target));
    return 0;
}