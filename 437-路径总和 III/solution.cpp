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
    unordered_map<long long, int> hash;
    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1;
        return dfs(root, targetSum, 0);
    }
    
    int dfs(TreeNode* root, int targetSum, long long presum){
        if(!root) return 0;
        int temp = 0;
        presum = presum + root -> val;
        if(hash.count(presum - targetSum)) temp = hash[presum - targetSum];
        hash[presum]++;
        temp = temp + dfs(root -> left, targetSum, presum);
        temp = temp + dfs(root -> right, targetSum, presum);
        hash[presum]--;
        return temp;
    }
};