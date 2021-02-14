#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while (m >=0 && n >=0) {
            nums1[pos--] = (nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
        while (n >= 0) 
            nums1[pos--] = nums2[n--];
    }
    void print(vector<int> v) {
        for (auto i: v)
            cout << i << " ";
    }
};


int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m(3),n(3);
    sol.merge(nums1, m, nums2, n);
    sol.print(nums1);
}