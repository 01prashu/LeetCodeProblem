#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *BuildTree(Node *root)
{
    cout<<"Enter Data: ";
    int d;
    cin>>d;
    root=new Node(d);
    if(d == -1)
    {
        return NULL;
    }
    cout<<"Inserting Left of "<<d<<endl;
    root->left=BuildTree(root->left);
    cout<<"Inserting Rigth Of "<<d<<endl;
    root->right=BuildTree(root->right);
    return root;
}
void InorderTraversal(Node *root )
{
    
    if(root == NULL)
    {
        return ;
    }
    InorderTraversal(root->left );
    cout<<root->data<<" ";
    InorderTraversal(root->right );
    
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *t=q.front();
        cout<<t->data<<" ";
        q.pop();
        if(t->left)
        {
            q.push(t->left);
        }
        if(t->right)
        {
            q.push(t->right);
        }
    }
    cout<<endl;
}
