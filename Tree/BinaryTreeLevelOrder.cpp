#include "Tree.h"
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            Node *t = q.front();
            temp.push_back(t->data);
            q.pop();
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    LevelOrderTraversal(root);
    cout<<" Result"<<endl;
    vector<vector<int>>result=levelOrder(root);
    cout<<"[";
    for(auto i: result)
    {
        cout<<"[";
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
    return 0;
}