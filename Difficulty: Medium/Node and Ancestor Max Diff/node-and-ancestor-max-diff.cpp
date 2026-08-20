class Solution {
public:
    void dfs(Node* root, int maxAncestor, int &ans) {
        if (root == nullptr)
            return;

        // Ancestor - current node
        ans = max(ans, maxAncestor - root->data);

        // Current node can become an ancestor for its children
        maxAncestor = max(maxAncestor, root->data);

        dfs(root->left, maxAncestor, ans);
        dfs(root->right, maxAncestor, ans);
    }

    int maxDiff(Node* root) {
        int ans = INT_MIN;

        // Root itself is the first ancestor
        dfs(root->left, root->data, ans);
        dfs(root->right, root->data, ans);

        return ans;
    }
};