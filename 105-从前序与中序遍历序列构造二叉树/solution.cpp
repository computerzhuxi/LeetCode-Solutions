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
private:
    unordered_map<int,int> index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                            int preorder_left, int preorder_right, 
                            int inorder_left, int inorder_right)
    {
        if(preorder_left > preorder_right)
            return nullptr;

        int p_root = preorder_left;

        int i_root = index[preorder[p_root]];

        TreeNode* root = new TreeNode(preorder[p_root]);

        int l_size = i_root - inorder_left;
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + l_size, inorder_left, i_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + 1 + l_size, preorder_right, i_root + 1, inorder_right);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};