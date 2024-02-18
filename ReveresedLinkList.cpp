//
// Created by SnirN on 2/10/2024.
//

typedef struct Node {
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}

    Node(int _val) : val(_val), next(nullptr) {};

    Node(int _val, Node *_node) : val(_val), next(_node) {};
} Node;


class RLL {
public:
    Node *reverseList(Node *head) {
        Node *curr = head->next, *prev = head, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

};