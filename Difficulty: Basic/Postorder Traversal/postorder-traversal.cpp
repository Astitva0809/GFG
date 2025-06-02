/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
  
  void postorder(Node* root, vector<int> &res){
    if(root == NULL) return;
    postorder(root->left, res);
    
    postorder(root->right, res);
    res.push_back(root->data);
}

     
  
  
  
   
    vector<int> postOrder(Node* root) {
        // Your code here
           vector<int> res;
        postorder(root, res);
        return res;
    }
};