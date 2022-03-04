// https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/challenge-1796

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node *left = nullptr, *right = nullptr;
    int data;

    explicit Node(int data) : data(data) {}
};

Node *root;

Node *add(Node *root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else if (data > root->data) {
        root->right = add(root->right, data);
    } else if (data < root->data) {
        root->left = add(root->left, data);
    }

    return root;
}

void print(Node *root) {
    if (root) {
        cout << root->data << ' ';
        print(root->left);
        print(root->right);
    }
}

void print_odd_layers(Node *root) {
    if (root == nullptr) {
        return;
    }

    queue<Node *> q;
    q.push(root);

    int layer = 1;
    while (!q.empty()) {
        int s = (int) q.size();
        while (s--) {
            Node *cur = q.front();
            q.pop();
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
            if (layer & 1) {
                cout << cur->data << ' ';
            }
        }

        ++layer;
    }
}

Node *minDataNode(Node *root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    }

    return minDataNode(root->left);
}

Node *remove(Node *root, int data) {
    if (root == nullptr) {
        return root;
    } else if (data > root->data) {
        root->right = remove(root->right, data);
    } else if (data < root->data) {
        root->left = remove(root->left, data);
    } else {
        if (root->left && root->right) {
            Node *temp = minDataNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        } else if (root->left) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else if (root->right) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else {
            delete root;
            root = nullptr;
        }
    }
    return root;
}

int main() {
    int q;
    cin >> q;

    string cmd;
    int data;
    while (q--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> data;
            root = add(root, data);
        } else if (cmd == "print") {
            print(root);
        } else if (cmd == "print_odd_layers") {
            print_odd_layers(root);
        } else if (cmd == "remove") {
            cin >> data;
            root = remove(root, data);
        }
    }

    return 0;
}