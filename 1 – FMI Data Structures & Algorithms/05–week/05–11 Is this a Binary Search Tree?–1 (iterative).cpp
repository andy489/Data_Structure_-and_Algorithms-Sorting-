// https://www.hackerrank.com/challenges/is-binary-search-tree/problem

vector<int> vec;

void inorder(Node *root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    vec.emplace_back(root->data);
    inorder(root->right);
}

bool checkBST(Node *root) {
    vec.reserve(1e3);

    inorder(root);
    int SIZE = vec.size();

    for (int i = 1; i < SIZE; ++i) {
        if (vec[i] <= vec[i - 1]) {
            return false;
        }
    }
    
    return true;
}
