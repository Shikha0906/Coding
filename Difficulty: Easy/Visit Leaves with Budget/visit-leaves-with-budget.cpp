/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        if (!root) return 0;

        queue<pair<Node*, int>> q; // Pair: {node, level}
        q.push({root, 1});

        int count = 0;

        while (!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();

            // Check if current node is a leaf node
            if (!curr->left && !curr->right) {
                if (k >= level) {
                    k -= level;
                    count++;
                } else {
                    break; // Since levels increase monotonically, no further leaves can be afforded
                }
            }

            if (curr->left) q.push({curr->left, level + 1});
            if (curr->right) q.push({curr->right, level + 1});
        }

        return count;
    }
};