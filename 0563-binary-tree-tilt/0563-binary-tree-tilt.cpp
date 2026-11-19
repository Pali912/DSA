class Solution {
public:
    int totalTilt = 0;

    int sum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        totalTilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        totalTilt = 0;
        sum(root);
        return totalTilt;
    }
};