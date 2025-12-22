class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;

        while (temp) {
            if (visited[temp]) {
                return true;   // same node visited again
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};
