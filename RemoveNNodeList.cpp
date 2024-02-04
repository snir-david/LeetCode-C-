//
// Created by SnirN on 01/02/2024.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RNL {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head || !head->next){
            return nullptr;
        }
        int numOfNodes = 1;
        ListNode* currentHead = head;
        ListNode* currentNode = head->next;
        while(currentNode != nullptr){
            if(numOfNodes >= n + 1){
                currentHead = currentHead->next;
            }
            numOfNodes++;
            currentNode = currentNode->next;
        }
        if(numOfNodes == n){
            head = head->next;
        } else {
            currentHead->next = currentHead->next->next;
        }
        return head;
    }
};