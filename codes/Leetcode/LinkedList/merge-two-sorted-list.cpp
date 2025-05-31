/*
    Author: Asif
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>s;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        while (temp1 != nullptr) {
            s.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            s.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(s.begin(), s.end());

        // new list to store all the elements 
        // from the vector
        ListNode* head = new ListNode(s[0]);
        ListNode* temp = head;
        for (int i = 1; i < s.size(); i++) {
            ListNode* newNode = new ListNode(s[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};

/*
stored all the values in a vector from 2 lists, sorted, 
then created a new list with all the  values from the vector and 
returned the head of the new linkedlist.
*/