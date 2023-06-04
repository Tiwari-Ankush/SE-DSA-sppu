// Beginning with an empty binary search tree, Construct binary search tree by inserting 
// the values in the order given. After constructing a binary tree -
// i. Insert new node, 
// ii. Find number of nodes in longest path from root, 
// iii. Minimum data 
//     value found in the tree, 
// iv. Change a tree so that the roles of the left and right pointers 
//     are swapped at every node, 
// v. Search a value

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    int findLongestPath() {
        return findLongestPath(root);
    }

    int findMinimumValue() {
        return findMinimumValue(root);
    }

    void swapPointers() {
        swapPointers(root);
    }

    bool search(int value) {
        return searchValue(root, value);
    }

    void display() {
        displayTree(root);
        cout << endl;
    }

private:
    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertNode(root->left, value);
        } else if (value > root->data) {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    int findLongestPath(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftPath = findLongestPath(root->left);
        int rightPath = findLongestPath(root->right);

        return 1 + max(leftPath, rightPath);
    }

    int findMinimumValue(Node* root) {
        if (root == nullptr) {
            cout << "Error: Tree is empty." << endl;
            return -1; // Assuming -1 represents an invalid value
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root->data;
    }

    void swapPointers(Node* root) {
        if (root == nullptr) {
            return;
        }

        swapPointers(root->left);
        swapPointers(root->right);

        // Swap the left and right pointers
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    bool searchValue(Node* root, int targetValue) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == targetValue) {
            return true;
        }

        if (targetValue < root->data) {
            return searchValue(root->left, targetValue);
        } else {
            return searchValue(root->right, targetValue);
        }
    }

    void displayTree(Node* root) {
        if (root != nullptr) {
            displayTree(root->left);
            cout << root->data << " ";
            displayTree(root->right);
        }
    }
};

int main() {
    BST bst;

    // // Construct the binary search tree
    // int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    // int size = sizeof(values) / sizeof(values[0]);

    // for (int i = 0; i < size; i++) {
    //     bst.insert(values[i]);
    // }

    int choice;
    int value;
    while (true) {
        cout << "\nBinary Search Tree Operations" << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. Find the number of nodes in the longest path" << endl;
        cout << "3. Find the minimum value" << endl;
        cout << "4. Swap left and right pointers at every node" << endl;
        cout << "5. Search for a value" << endl;
        cout << "6. Display the tree" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Number of nodes in the longest path: " << bst.findLongestPath() << endl;
                break;
            case 3:
                cout << "Minimum value in the tree: " << bst.findMinimumValue() << endl;
                break;
            case 4:
                bst.swapPointers();
                cout << "Left and right pointers swapped at every node." << endl;
                break;
            case 5:
                cout << "Enter the value to search for: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << "Value " << value << " found in the tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;
            case 6:
                cout << "Binary Search Tree: ";
                bst.display();
                break;
            case 7:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
