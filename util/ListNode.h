#ifndef SHORAN_CPP_LISTNODE_H
#define SHORAN_CPP_LISTNODE_H
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ////////////////////////////////////////////////////////
    static ListNode * createListNode(const std::vector<int> &data) {
        ListNode *r = new ListNode();
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            r->next = new ListNode(*it, r->next);
        }
        return r->next;
    }

    std::vector<int> getData() {
        std::vector<int> data;
        for (ListNode *n = this; n != nullptr; n = n->next) {
            data.push_back(n->val);
        }
        return data;
    }
};



#endif //SHORAN_CPP_LISTNODE_H
