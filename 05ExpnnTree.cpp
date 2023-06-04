// Construct an expression tree from the given prefix expression eg. +--a*bc/def and 
// traverse it using post order traversal (non recursive) 
// and then delete the entire tree


#include <iostream>
#include <string>

using namespace std;

// Structure for representing a node of the expression tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to construct an expression tree from a prefix expression
Node* constructExpressionTree(const string& prefixExpression, int& index) {
    char c = prefixExpression[index++];
    Node* newNode = createNode(c);

    if (isOperator(c)) {
        newNode->left = constructExpressionTree(prefixExpression, index);
        newNode->right = constructExpressionTree(prefixExpression, index);
    }

    return newNode;
}

// Function for post-order traversal (non-recursive)
void postOrderTraversal(Node* root) {
    Node* current = root;
    Node* prev = nullptr;
    string result = "";

    while (current) {
        if (!current->left) {
            result += current->data;
            current = current->right;
        } else {
            prev = current->left;
            while (prev->right && prev->right != current) {
                prev = prev->right;
            }

            if (!prev->right) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = nullptr;
                result += current->data;
                current = current->right;
            }
        }
    }

    for (int i = result.length() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}

// Function to delete the entire expression tree
void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
// dynamic 
    // string prefixExpression;
    // cout << "Enter the prefix expression: ";
    // getline(cin, prefixExpression);

// static 
    const char*  prefixExpression = "+-a*bc/def";


    int index = 0;
    Node* root = constructExpressionTree(prefixExpression, index);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Delete the entire expression tree
    deleteTree(root);

    return 0;
}