#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

TreeNode* buildTree(){
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    if(data==-1) return nullptr;
    // creation of a node
    TreeNode* root=new TreeNode(data);

    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void preOrderTraversal(TreeNode* root){
    if(root==nullptr) return ;
    // print the node
    cout << root->val << " ";
    // left call of the tree
    preOrderTraversal(root->left);
    // right call of the tree
    preOrderTraversal(root->right);
}

 void solve(TreeNode* root,int sum,int lvl,int& maxLvl,int& maxSum){
       if(root==nullptr) return ;
       sum += root->val;
       if(lvl>maxLvl){4 2 7 
           maxSum=sum;
           maxLvl=max(lvl,maxLvl);
       }
       if(lvl==maxLvl){
           maxSum=max(maxSum,sum);
       }
       
       solve(root->left,sum,lvl+1,maxLvl,maxSum);
       solve(root->right,sum,lvl+1,maxLvl,maxSum);
   }

int sumOfLongRootToLeafPath(TreeNode* root){
    int sum=0;
    int lvl=0;
    int maxLvl=0;
    int maxSum=0;
    solve(root,sum,lvl,maxLvl,maxSum);
    return maxSum;
}

int main()
{
    TreeNode* root=nullptr;
    root=buildTree();
    preOrderTraversal(root);
    cout << endl;
    int ans=sumOfLongRootToLeafPath(root);
    cout << "Answer is:" << ans << endl;
    return 0;
}

// Input Tree Value : 4 2 7 -1 -1 1 5 -1 1 -1 -1 -1 5 2 -1 8 5 -1 -1 -1 3 -1 -1 