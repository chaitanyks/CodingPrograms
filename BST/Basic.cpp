#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (root->data < data) {
        root->right = insert(root->right, data);
    } else if (root->data > data) {
        root->left = insert(root->left, data);
    }

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *successor(Node *root) {
    if (root == NULL) {
        return root;
    }
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL)
        return root;

    if (root->data < data) {
        root->right = deleteNode(root->right, data);
    }

    if (root->data > data) {
        root->left = deleteNode(root->left, data);
    }

    if (root->data == data) {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }

        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL) {
            Node *temp = successor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

bool search(Node *root, int data) {
    if (root == NULL)
        return false;

    if (root->data == data) {
        return true;
    } else if (root->data > data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    // your code goes here
    Node *root = NULL;
// 	root = newNode(50);
// 	insert(root,15);
// 	insert(root,35);
// 	insert(root,95);
// 	insert(root,25);
// 	insert(root,6);
// 	insert(root,4);
// 	insert(root,2);
// 	insert(root,1);
// 	//Inorder print
// 	Inorder(root);
// 	delete(95);

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << endl;
    if (search(root, 80)) {
        cout << "Value found" << endl;
    } else {
        cout << "Value not found" << endl;
    }


    if (search(root, 180)) {
        cout << "Value found" << endl;
    } else {
        cout << "Value not found" << endl;
    }
    return 0;
}
