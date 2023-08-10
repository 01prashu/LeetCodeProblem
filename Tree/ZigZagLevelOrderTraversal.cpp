#include "Tree.h"
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    bool leftToright = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *t = q.front();
            int index;
            if (leftToright == true)
            {
                index = i;
            }
            else
            {
                index = size - i - 1;
            }
            temp[index] = t->data;
            q.pop();
            if (t->left != NULL)
            {
                q.push(t->left);
            }
            if (t->right != NULL)
            {
                q.push(t->right);
            }
        }
        leftToright = !leftToright;
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
    vector<vector<int>>result=zigzagLevelOrder(root);
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
                 Expected o/P:  [[3] [20 9] [15 7]]
*/
