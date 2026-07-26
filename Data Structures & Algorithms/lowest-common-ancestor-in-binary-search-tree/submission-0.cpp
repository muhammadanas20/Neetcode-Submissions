/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr != nullptr){
            if(p->val > curr->val && q->val > curr->val) {
                //both target is greater
                //move to right
                curr = curr->right;
            }
            else if(p->val < curr->val && q->val < curr->val){
                //both target is smaller
                //move to left
                curr = curr->left;
            }else{
                // Split point found (or current matches p or q)
                return curr;
            }
        }
        return nullptr;
    }
};
