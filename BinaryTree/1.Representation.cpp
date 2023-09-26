#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node* root){
    if(root == NULL)return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);     
}
void postorder(Node* root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(5);
    root->left->right = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    // level order traversal
    cout << endl;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout << node->data<<" ";
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }

    // iterative traversal
    cout << endl;
    stack<Node*> s;

    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        cout << node->data << " ";
        if(node->right != NULL)
            s.push(node->right);
        if(node->left != NULL)
            s.push(node->left);
    }
    
    // iterative inorder traversal
    cout << endl;
    stack<Node*> s1;
    Node* curr = root;
    while(curr != NULL || !s1.empty()){
        while(curr != NULL){
            s1.push(curr);
            curr = curr->left;
        }
        curr = s1.top();
        s1.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    // iterative postorder traversal
    cout << endl;   
    stack<Node*> s2;
    s2.push(root);
    stack<int> ans;
    while(!s2.empty()){
        Node* node = s2.top();
        s2.pop();
        ans.push(node->data);
        if(node->left != NULL)
            s2.push(node->left);
        if(node->right != NULL)
            s2.push(node->right);
    }
    
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}


