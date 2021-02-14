#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) { 
        if (head == NULL || head->next == NULL)
            return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
    
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { 
                fast = head;// there is a cycle
                while(slow != fast) {               // found the entry location
                    slow  = slow->next;
                    fast = fast->next;
                }
            return fast;
            }
        }
        return nullptr;    
    }

    void printListNode(ListNode *head){
        cout << head->val;
    }
};

int main()
{
    Solution sol;
    // cycle [3,2,0,-4] connect at pos 1 val=2
    ListNode*  head = new ListNode(3);
    ListNode* dummy = head;
    head->next = new ListNode(2);
    head = head->next;
    ListNode* connect = head;
    head->next = new ListNode(0);
    head = head->next;
    head->next = new ListNode(-4);
    head = head->next;
    head->next = connect;
    
    sol.printListNode(sol.detectCycle(dummy));
    return 0;
}