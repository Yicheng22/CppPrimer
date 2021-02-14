#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t)  
            m[c]++;
      
        int count = t.size();
        int l = 0, r =0, f = 0, minLength = INT_MAX;
    
        bool check=false; // to check at least for 1 time count is reaching 0
        while (r < s.size())
        {
            if (m[s[r]] > 0)  count--;

            m[s[r]]--;
            r++;
            if(count==0) 
                check=true;
            while (count == 0){
                if (r - l < minLength){
                    minLength = r - l;
                    f = l;
                }
                if (m[s[l]] >= 0)  count++;

                m[s[l]]++;
                l++;
            }
        }
        if(check) return s.substr(f, minLength);
        else return "";
    }
};

int main() 
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s,t);
    return 0;
}