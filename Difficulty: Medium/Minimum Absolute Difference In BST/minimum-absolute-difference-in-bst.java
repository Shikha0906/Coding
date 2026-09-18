class Solution {

    int prev = -1;
    int ans = Integer.MAX_VALUE;

    int absDiff(Node root) {
        inorder(root);
        return ans;
    }

    void inorder(Node root) {
        if (root == null) {
            return;
        }

        // Visit left subtree
        inorder(root.left);

        // Process current node
        if (prev != -1) {
            ans = Math.min(ans, root.data - prev);
        }

        prev = root.data;

        // Visit right subtree
        inorder(root.right);
    }
}