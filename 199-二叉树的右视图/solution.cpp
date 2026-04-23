class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;

        if(!root)
            return rightView;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            while(size)
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if(size == 1)
                    rightView.push_back(node->val);
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);
                size--;
            }
        }

        return rightView;
    }
};