#include<iostream>
#include<queue>
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

TreeNode* buildTree(){
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    if(data==-1) return nullptr;
    // create a new Node
    TreeNode* root=new TreeNode(data);

    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void levelOrderTraverse(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();

        if(temp==nullptr){
            cout << endl;
            if(!q.empty()) q.push(nullptr);
        }
        else{
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void inorderTraversal(TreeNode* root){
    if(root==nullptr) return ;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void morisTraversal(TreeNode* root){
    TreeNode* curr=root;

    while(curr){
        // if curr left is null then we visit the node and store it and move right and on moving right we move upper node of the tree
        if(curr->left==nullptr){
            cout << curr->data << " ";
            curr=curr->right;
        }
        // if curr left part is not null then we create a link using pred pointer to move upward in the tree
        else{
            // find inorder predecessor
            TreeNode* pred=curr->left;

            while(pred->right && pred->right != curr){
                pred=pred->right;
            }

            // if pred right is null then join pred right to the curr to create a links
            if(pred->right==nullptr){
                pred->right=curr;
                curr=curr->left;
            }
            
            // if pred right is not null so dont stuck in a infinite loop so make pred->right is null ans also store ans
            else{
                pred->right=nullptr;
                cout << curr->data << " ";
                curr=curr->right;
            }
        }
    }
}

void flattenBinaryTreeToLL(TreeNode* root){
    TreeNode* curr=root;
    while(curr){
        if(curr->left==nullptr) curr=curr->right;
        else{
            // find predeccessor
            TreeNode* pred=curr->left;
            while(pred->right) pred=pred->right;
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
    }
}

void preorderTraversal(TreeNode* root){
    if(root==nullptr) return ;
    // print the node
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void printLL(TreeNode* root){
    TreeNode* curr=root;
    cout << root-> data << " ";
    while(curr!=nullptr){
        cout << curr->right->data << " ";
        curr=curr->right;
    }
}

int main()
{
    TreeNode* root=nullptr;
    root = buildTree();
    levelOrderTraverse(root);
    cout << "Inorder Traversal:" << endl;
    // inorderTraversal(root);
    // cout << endl;
    // cout << "Morris Traversal:" << endl;
    // morisTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    flattenBinaryTreeToLL(root);
    cout << endl;
    cout << "Prinitng a Linked list" << endl;
    printLL(root);
    return 0;
}


// input tree : 1 2 4 -1 -1 5 6 -1 -1 -1 3 7 -1 -1 8 -1 -1
// input value : 8 5 -1 19 18 20 -1 21 -1 -1 -1 -1 12 24 -1 -1 22 28 -1 -1 -1
// input tree : 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1 