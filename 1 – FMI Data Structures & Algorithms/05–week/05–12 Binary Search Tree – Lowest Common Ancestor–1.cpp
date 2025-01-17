// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

Node *lca(Node *root, int v1, int v2) {
    if (root == nullptr){
        return nullptr;
    }

    if (root->data < v1 && root->data < v2){
        return lca(root->right, v1, v2);
    }

    if (root->data > v1 && root->data > v2){
        return lca(root->left, v1, v2);
    }

    return root;
}
