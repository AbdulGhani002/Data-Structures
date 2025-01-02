#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *right;
  Node *left;
};
void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data;
  inorder(root->right);
}

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data;
  inorder(root->left);
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  inorder(root->right);
  cout << root->data;
}

Node *insert(Node *root, char data) {
  if (root == NULL) {
    root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else if (data <= root->data)
    root->left = insert(root->left, data);
  else {
    root->right = insert(root->right, data);
  }
  return root;
}
int main(void) {
  Node *root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 5);
  root = insert(root, 7);
  root = insert(root, 3);
  root = insert(root, 3);

  cout << "Preorder: ";
  preorder(root);
  cout << endl;

  cout << "Inorder: ";
  inorder(root);
  cout << endl;

  cout << "Postorder: ";
  postorder(root);
  cout << endl;
}