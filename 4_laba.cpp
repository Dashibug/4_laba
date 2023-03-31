// реализациz бинарного дерева на связной памяти
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == NULL) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = NULL;
        while (true) {
            parent = current;
            if (value < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }

    void inorderTraversal(Node* node) {//неупорядоч обход
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void printInorder() {
        inorderTraversal(root);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    cout << "Обход: ";
    tree.printInorder();
    return 0;
}

//Пример реализации бинарного дерева на смежной памяти
#include <iostream>

//using namespace std;
//
//const int MAX_SIZE = 100;
//
//class BinaryTree {
//public:
//    int data[MAX_SIZE];
//    int size;
//
//    BinaryTree() {
//        size = 0;
//    }
//
//    void insert(int value) {
//        if (size == MAX_SIZE) {
//            cout << "Error: Maximum size of tree exceeded." << endl;
//            return;
//        }
//        data[size++] = value;
//    }
//
//    void inorderTraversal(int index) {
//        if (index < size) {
//            inorderTraversal(2 * index + 1);
//            cout << data[index] << " ";
//            inorderTraversal(2 * index + 2);
//        }
//    }
//
//    void printInorder() {
//        inorderTraversal(0);
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    BinaryTree tree;
//    tree.insert(50);
//    tree.insert(30);
//    tree.insert(20);
//    tree.insert(40);
//    tree.insert(70);
//    tree.insert(60);
//    tree.insert(80);
//    cout << "Inorder traversal: ";
//    tree.printInorder();
//    return 0;
//}