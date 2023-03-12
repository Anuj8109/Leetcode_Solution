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
    ListNode* helper(ListNode* p,ListNode* q){
        if(!p) return q;
        else if(!q) return p;
        // cout<<p->val<<" "<<q->val<<endl;
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(p && q){
            if(p->val > q->val){
                temp->next = q;
                q = q->next;
                // temp = temp->next;
            }else{
                temp->next = p;
                p = p->next;       
            }
            temp = temp->next;
        }
        if(p) temp->next = p;
        else if(q) temp->next = q;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        // if(n == 1) return lists[0];
        ListNode* ans = lists[0];
        while(n > 1){
            int i = 0;
            for(i=0;i + 1<n;i+=2){
                lists[i/2] = helper(lists[i],lists[i+1]);
            }
            // cout<<i<<endl;
            if(n%2) lists[n/2] = lists[n-1];
            n = n/2 + n%2;
            // cout<<n<<" "<<lists[0]->val<<endl;
        }
        // for(int i=1;i<n;i++){
        //     ans = helper(ans,lists[i]);
        // }
        return lists[0];
    }
};