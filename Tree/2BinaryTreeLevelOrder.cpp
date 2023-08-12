#include "Tree.h"
vector<vector<int>> levelOrderBottom(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<vector<int>> st;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();
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
        st.push(temp);
    }
    while (!st.empty())
    {
        vector<int> t = st.top();
        ans.push_back(t);
        st.pop();
    }
    return ans;
}
int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    LevelOrderTraversal(root);
    cout<<" Result"<<endl;
    vector<vector<int>>result=levelOrderBottom(root);
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
/*              3
               /  \
              9    20
                   /  \
                  15   7

                  I/O : 3 9 -1 -1 20 15 -1 -1 7 -1 -1 
                 Expected o/P:  [[15 7] [9 20] [3]]
*/