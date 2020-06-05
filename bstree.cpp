#include<iostream>
using namespace std;

struct bstree{
    int data;
    bstree *left;
    bstree *right;
};

bstree *createnewnode(int data)
{
    bstree * node =new bstree();
    node->data = data;
    node->left=node->right=NULL;
    return node;
}
bstree *insert(bstree*root,int data)
{
    if(root==NULL)
    {
        root = createnewnode(data);
        return root;
    }
    else if(data <= root->data)
    {
        root->left= insert(root->left,data);
    }
    else
    {
        root->right= insert(root->right,data);
    }
    return root;
}
bool search(bstree*root, int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data < root->data)
    {
        return search(root->left,data);
    }
    else
    {
        return search(root->right,data);
    }
}
int main()
{
    bstree * root=NULL;
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,3);
    root=insert(root,9);
    root=insert(root,2);
    root=insert(root,8);
    int n;
    cin>>n;
    if(search(root,n))
    cout<<"found";
    else
    cout<<"not found";
}
