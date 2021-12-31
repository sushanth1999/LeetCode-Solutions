#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int ans = INT_MIN;
    void dfs(TreeNode* root,int maxi,int mini) {
        if(root == NULL) {
            return;
        }
        
        maxi = max(maxi,root->val);
        mini = min(mini,root->val); 
        
        ans = max(ans,abs(maxi-mini));
        
        dfs(root->left,maxi,mini);
        dfs(root->right,maxi,mini);
        
    }
    int maxAncestorDiff(TreeNode* root) {
     
        ans = INT_MIN;
        dfs(root,root->val,root->val);
        return ans;
    }
};