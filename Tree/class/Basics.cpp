#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};


int main()
{
    TreeNode* root=new TreeNode(10);
    insertAtTree(root,20);
    insertAtTree(root,-1);
    insertAtTree(root,-1);
    insertAtTree(root,30);
    insertAtTree(root,-1);
    insertAtTree(root,-1);
    return 0;
}