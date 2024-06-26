#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left); 
    postOrderTraversal(root->right);  
    cout << root->val << " ";  
}

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
  
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    cout << "Post-order traversal of the binary tree is: ";
    postOrderTraversal(root);

    return 0;
}
