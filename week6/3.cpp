#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

vector<string> infixToPostfix(string infix) {
    stack<char> opStack;
    vector<string> postfix;
    string number;

    for (char& token : infix) {
        if (isalpha(token)) {
            postfix.push_back(string(1, token));
        } else if (token == '(') {
            opStack.push(token);
        } else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.pop(); // pop '('
        } else if (isOperator(token)) {
            while (!opStack.empty() && getPrecedence(opStack.top()) >= getPrecedence(token)) {
                postfix.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.push(token);
        }
    }
    while (!opStack.empty()) {
        postfix.push_back(string(1, opStack.top()));
        opStack.pop();
    }
    return postfix;
}

TreeNode* constructTree(const vector<string>& postfix) {
    stack<TreeNode*> nodeStack;
    for (const string& token : postfix) {
        if (isalpha(token[0])) {
            nodeStack.push(new TreeNode(token[0]));
        } else if (isOperator(token[0])) {
            TreeNode* right = nodeStack.top(); nodeStack.pop();
            TreeNode* left = nodeStack.top(); nodeStack.pop();
            TreeNode* newNode = new TreeNode(token[0]);
            newNode->left = left;
            newNode->right = right;
            nodeStack.push(newNode);
        }
    }
    return nodeStack.top();
}

void postOrder(TreeNode* root, string& result) {
    if (root) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result += root->value;
    }
}

void printTree(TreeNode* root, int depth, int pos, vector<vector<char>>& canvas) {
    if (root == nullptr) return;
    canvas[depth][pos] = root->value;
    if (root->left) {
        canvas[depth + 1][pos - 1] = '/';
        printTree(root->left, depth + 2, pos - 2, canvas);
    }
    if (root->right) {
        canvas[depth + 1][pos + 1] = '\\';
        printTree(root->right, depth + 2, pos + 2, canvas);
    }
}

int evaluateTree(TreeNode* root, map<char, int>& values) {
    if (root == nullptr) return 0;
    if (isalpha(root->value)) return values[root->value];
    int leftVal = evaluateTree(root->left, values);
    int rightVal = evaluateTree(root->right, values);
    switch (root->value) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

int main() {
    string infix;
    int n;
    cin >> infix >> n;
    map<char, int> values;
    for (int i = 0; i < n; ++i) {
        char var;
        int val;
        cin >> var >> val;
        values[var] = val;
    }

    // Step 1: Convert infix to postfix
    vector<string> postfix = infixToPostfix(infix);

    // Step 2: Construct expression tree
    TreeNode* root = constructTree(postfix);

    // Step 3: Post-order traversal to get postfix expression
    string postfixExpression;
    postOrder(root, postfixExpression);
    cout << postfixExpression << endl;

    // Step 4: Print the tree
    int depth = 4; // A rough estimation based on max length 50 and assuming balanced tree
    int width = 2 * (1 << (depth - 1)) - 1;
    vector<vector<char>> canvas(2 * depth - 1, vector<char>(width, ' '));
    printTree(root, 0, width / 2, canvas);
    for (auto& row : canvas) {
        for (auto& ch : row) {
            cout << ch;
        }
        cout << endl;
    }

    // Step 5: Evaluate expression tree
    int result = evaluateTree(root, values);
    cout << result << endl;

    return 0;
}

