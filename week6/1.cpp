#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int weight;
    Node* left;
    Node* right;

    Node(int w) : weight(w), left(nullptr), right(nullptr) {}
};

// 比较节点权重的函数，用于优先队列
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->weight > r->weight;
    }
};

Node* buildHuffmanTree(const vector<int>& weights) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // 将每个权重插入优先队列
    for (int weight : weights) {
        minHeap.push(new Node(weight));
    }

    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node(left->weight + right->weight);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

int calculateWeightedPathLength(Node* node, int depth) {
    if (!node->left && !node->right) {
        return node->weight * depth;
    }

    int total = 0;
    if (node->left) {
        total += calculateWeightedPathLength(node->left, depth + 1);
    }
    if (node->right) {
        total += calculateWeightedPathLength(node->right, depth + 1);
    }

    return total;
}

int minWeightedPathLength(const vector<int>& weights) {
    Node* huffmanTree = buildHuffmanTree(weights);
    return calculateWeightedPathLength(huffmanTree, 0);
}

int main() {
    vector<int> weights = {1, 1, 3, 5};
    int minPathLength = minWeightedPathLength(weights);
    cout << "最小外部路径长度总和: " << minPathLength << endl;
    return 0;
}

