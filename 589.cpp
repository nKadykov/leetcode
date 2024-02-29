#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void solve(Node* root, vector<int>& v) {
        if(root == NULL) {
            return;
        }
        v.push_back(root->val);
        for(int i = 0; i < (root->children).size(); i++) {
            solve((root->children)[i], v);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> v;
        solve(root, v);
        return v;
    }
};

int main() {
    Node* root1 = new Node(1);
    Node* node11 = new Node(3);
    Node* node12 = new Node(2);
    Node* node13 = new Node(4);
    Node* node14 = new Node(5);
    Node* node15 = new Node(6);
    vector<Node*> v11 {node11, node12, node13};
    vector<Node*> v12 {node14, node15};
    root1->children = v11;
    node11->children = v12;

    Node* root2 = new Node(1);
    Node* node21 = new Node(2);
    Node* node22 = new Node(3);
    Node* node23 = new Node(4);
    Node* node24 = new Node(5);
    Node* node25 = new Node(6);
    Node* node26 = new Node(7);
    Node* node27 = new Node(8);
    Node* node28 = new Node(9);
    Node* node29 = new Node(10);
    Node* node210 = new Node(11);
    Node* node211 = new Node(12);
    Node* node212 = new Node(13);
    Node* node213 = new Node(14);
    vector<Node*> v21 {node21, node22, node23, node24};
    vector<Node*> v22 {node25, node26};
    vector<Node*> v23 {node27};
    vector<Node*> v24 {node28, node29};
    vector<Node*> v25 {node210};
    vector<Node*> v26 {node211};
    vector<Node*> v27 {node212};
    vector<Node*> v28 {node213};
    root2->children = v21;
    node22->children = v22;
    node23->children = v23;
    node24->children = v24;
    node26->children = v25;
    node27->children = v26;
    node28->children = v27;
    node210->children = v28;

    Solution solution;

    vector<int> solution1 = solution.preorder(root1);
    vector<int> solution2 = solution.preorder(root2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}