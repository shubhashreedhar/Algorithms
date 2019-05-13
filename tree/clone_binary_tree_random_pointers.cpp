/* Given a binary tree, clone the tree where the random pointer points to any random node of the binary tree and can even point to NULL.
 */

/* Using Hashing */
void dfs1(Node* root1, Node** root2, unordered_map<Node*,Node*> &hash)
{
    if(root1 == NULL)
    {
        *root2 = NULL;
        return;
    }

    (*root2) = new Node();
    (*root2)->data = root1->data;
    dfs1(root1->left, &((*root2)->left), hash);
    dfs1(root1->right, &((*root2)->right), hash);
    hash[root1] = *root2;
}

void dfs2(Node* root1, Node* root2, unordered_map<Node*,Node*> &hash)
{
    if(root1 == NULL)
        return;

    root2->random = hash[root1->random];
    dfs2(root1->left,root2->left,hash);
    dfs2(root1->right,root2->right,hash);
}

/* The function should clone the passed tree and return
   root of the cloned tree */
Node* cloneTree(Node* root1)
{
   //Your code here
   unordered_map<Node*, Node*> hash;
   Node* root2 = NULL;
   dfs1(root1,&root2,hash);
   dfs2(root1,root2,hash);
   return root2;
}

/* Temporarily modifying the tree - To be done */
