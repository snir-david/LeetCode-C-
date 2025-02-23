//
// Created by SnirN on 2/21/2025.
//

#ifndef LEETCODE_150_C___MERGETWOSORTEDLISTS_HPP
#define LEETCODE_150_C___MERGETWOSORTEDLISTS_HPP
 //Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *mergedListHead = nullptr, *mergedListTail = nullptr;
    while(list1 || list2){
      bool isList1lesser = (!list1) ? false : (!list2) ? true : (list1->val < list2->val);
      ListNode *minNode =  isList1lesser ? list1 : list2;

      if(!mergedListHead){
        mergedListHead = mergedListTail = minNode;
      } else {
        mergedListTail->next = minNode;
      }
      mergedListTail = minNode;

      if(isList1lesser){
        list1 = list1->next;
      } else {
        list2 = list2->next;
      }
    }

    return mergedListHead;
  }
};
#endif // LEETCODE_150_C___MERGETWOSORTEDLISTS_HPP
