class Solution {
public:

    // Find LCA of first and second
    Node* findLCA(Node* root, int first, int second) {
        if (root == nullptr)
            return nullptr;

        if (root->data == first || root->data == second)
            return root;

        Node* left = findLCA(root->left, first, second);
        Node* right = findLCA(root->right, first, second);

        if (left && right)
            return root;

        return left ? left : right;
    }

    // Find number of turns from root to target.
    // dir:
    // 0 = left
    // 1 = right
    // -1 = no previous direction
    bool findTurns(Node* root, int target, int dir,
                   int turns, int& result) {

        if (root == nullptr)
            return false;

        if (root->data == target) {
            result = turns;
            return true;
        }

        // Go left
        if (root->left) {
            int newTurns = turns;

            if (dir != -1 && dir != 0)
                newTurns++;

            if (findTurns(root->left, target, 0,
                          newTurns, result))
                return true;
        }

        // Go right
        if (root->right) {
            int newTurns = turns;

            if (dir != -1 && dir != 1)
                newTurns++;

            if (findTurns(root->right, target, 1,
                          newTurns, result))
                return true;
        }

        return false;
    }

    int numberOfTurns(Node* root, int first, int second) {

        if (root == nullptr)
            return -1;

        Node* lca = findLCA(root, first, second);

        if (lca == nullptr)
            return -1;

        int turnsFirst = 0;
        int turnsSecond = 0;

        bool foundFirst = true;
        bool foundSecond = true;

        // Find turns from LCA -> first
        if (lca->data != first) {
            turnsFirst = 0;
            foundFirst = findTurns(
                lca, first, -1, 0, turnsFirst
            );
        }

        // Find turns from LCA -> second
        if (lca->data != second) {
            turnsSecond = 0;
            foundSecond = findTurns(
                lca, second, -1, 0, turnsSecond
            );
        }

        if (!foundFirst || !foundSecond)
            return -1;

        // If both nodes are in the same direction from LCA,
        // we should NOT add a turn at LCA.
        if (lca->data != first && lca->data != second) {

            // Determine first direction
            int dirFirst = -1;
            int dirSecond = -1;

            Node* cur = lca;

            // Find first direction
            vector<int> pathFirst;
            vector<int> pathSecond;

            getDirections(lca, first, pathFirst);
            getDirections(lca, second, pathSecond);

            if (!pathFirst.empty())
                dirFirst = pathFirst[0];

            if (!pathSecond.empty())
                dirSecond = pathSecond[0];

            // Moving from first -> LCA -> second:
            // if directions differ, there is a turn at LCA.
            if (dirFirst != dirSecond)
                return turnsFirst + turnsSecond + 1;

            return turnsFirst + turnsSecond;
        }

        // One node is LCA.
        int result = turnsFirst + turnsSecond;

        // Straight path means -1.
        return result == 0 ? -1 : result;
    }

    bool getDirections(Node* root, int target, vector<int>& path) {

        if (root == nullptr)
            return false;

        if (root->data == target)
            return true;

        // Left = 0
        path.push_back(0);

        if (getDirections(root->left, target, path))
            return true;

        path.pop_back();

        // Right = 1
        path.push_back(1);

        if (getDirections(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }
};