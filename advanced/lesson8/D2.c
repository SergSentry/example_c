/*
 D2 Найти брата
*/

struct tree * findBrother(struct tree *root, int key) {
    if (root == NULL)
        return NULL;

    if (root->key == key) {
         struct tree * parent = root->parent;
         if (parent != NULL) {
            if (parent->left != NULL && parent->left == root)
                return parent->right;
            else if (parent->right != NULL && parent->right == root)
                return parent->left;
            else
                return NULL;
         }

         return NULL;
    }

    if (key < root->key)
       return findBrother(root->left, key);
    else
       return findBrother(root->right, key);
}
