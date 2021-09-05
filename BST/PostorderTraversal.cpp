class Solution
{
    vector<int> result;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }
};