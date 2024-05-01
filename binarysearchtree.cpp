// Beginning with an empty binary search tree, Construct a binary search tree by inserting
// the values in the order given. After constructing a binary tree
// i.Insert new node
// ii.Find number of nodes in longest path
// iii.Minimum data value found in the tree
// iv.Change a tree so that the roles of the left and right pointers are swapped
// at every node
// v.
// Search a value



#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// Binary Search Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the number of nodes in the longest path
int longestPath(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(longestPath(root->left), longestPath(root->right));
}

// Function to find the minimum data value in the tree
int minValue(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX;
    }

    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);

    return min(root->data, min(leftMin, rightMin));
}

// Function to swap left and right pointers at every node
void swapChildren(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapChildren(root->left);
    swapChildren(root->right);
}

// Function to search for a value in the BST
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to perform level order traversal (Breadth First Search) of the BST
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Function to deallocate memory allocated for the BST nodes
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Constructing the binary search tree
    TreeNode* root = nullptr;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        root = insert(root, values[i]);
    }

    // i. Insert new node
    root = insert(root, 9);

    // ii. Find number of nodes in the longest path
    cout << "Number of nodes in longest path: " << longestPath(root) << endl;

    // iii. Minimum data value found in the tree
    cout << "Minimum data value in the tree: " << minValue(root) << endl;

    // iv. Change the tree so that the roles of the left and right pointers are swapped
    swapChildren(root);

    // v. Search for a value
    int valueToSearch = 6;
    cout << "Value " << valueToSearch << " found: " << (search(root, valueToSearch) ? "true" : "false") << endl;

    // Displaying the modified tree using level order traversal
    cout << "Modified tree after swapping children: ";
    levelOrderTraversal(root);
    cout << endl;

    // Deallocate memory for the BST nodes
    deleteTree(root);

    return 0;
}
