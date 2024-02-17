#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return nullptr;
        }
        queue<Node*> nodes;
        nodes.push(root);
        while(nodes.size()) {
            Node* right = nullptr;
            for(int i = nodes.size(); i; i--) {
                auto node = nodes.front();
                nodes.pop();
                node->next = right;
                right = node;
                if(node->right) {
                    nodes.push(node->right), nodes.push(node->left);
                }
            }
        }
        return root;
    }
};

int main() {
    Node* root1 = new Node(1);
    Node* node11 = new Node(2);
    Node* node12 = new Node(3);
    Node* node13 = new Node(4);
    Node* node14 = new Node(5);
    Node* node15 = new Node(6);
    Node* node16 = new Node(7);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->left = node15;
    node12->right = node16;

    Node* root2;

    Solution solution;

    Node* solution1 = solution.connect(root1);
    Node* solution2 = solution.connect(root2);

    return 0;
}