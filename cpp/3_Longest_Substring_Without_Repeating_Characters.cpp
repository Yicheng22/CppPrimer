#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // optimized sliding window
        int size  = s.size();
        if (size < 2)
            return size;
        // list with [0] * 128, use for ASCII map
        vector<int> map(128,0);
        int length(0);
        for (int i(0), j(0); j < size; j++) {
            // update beginning of substring
            i = max(map[s.at(j)],i);
            // update the longest length
            length = max(length,j - i + 1);
            // if encountered, new start need increase 1
            map[s.at(j)] = j + 1;
        }
        return length;
    }
};

int main()
{
    Solution sol;
    
    string s{"abcabcbb"};
    cout << sol.lengthOfLongestSubstring(s) << endl;
    vector<int> test(100,10);
    test[97] = 22;
    cout << test['a'] << endl;

    return 0;
}