/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
  void InOrder(Node* root, vector<int> &res){
    if(root == NULL) return;
    InOrder(root->left, res);
    res.push_back(root->data);
    InOrder(root->right, res);
}


    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> res;
        InOrder(root, res);
        return res;
    }
};