#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry(0);
        int x,y;
        
        while (l1 != nullptr || l2 != nullptr){
            if (l1 != nullptr){
                x = l1->val;
                l1 = l1->next;
            } else x = 0;
            if (l2 != nullptr){
                y = l2->val;
                l2 = l2->next;
            } else y = 0;

            int sum = x + y + carry;
            curr->next = new ListNode(sum % 10);
            curr=curr->next;
            // update carry
            carry = sum / 10;      
        }
        // if carry to the new bit
        if (carry > 0)
            curr->next = new ListNode(carry);
        return head->next;
    }

    ListNode* vectorToListNode(vector<int> nums){
        ListNode* head;
        ListNode* curr = head;
        for (int i(0); i < nums.size(); i++) {
            curr->next = new ListNode(nums[i]);
            curr = curr->next;          
        }
        return head->next;
    }

    void printListNode(ListNode* l){
        while (l!=nullptr) {
        cout << l->val << " " ;
        l = l->next;
    }
    cout << endl;
    }
};

int main()
{
    Solution sol;
    
    vector<int> nums1 = {2,4,3};
    vector<int> nums2 = {5,6,6};
    ListNode* l1 = sol.vectorToListNode(nums1);
    ListNode* l2 = sol.vectorToListNode(nums2);
    
    ListNode* head;
    head = sol.addTwoNumbers(l1,l2);
    sol.printListNode(head);
    return 0;
}