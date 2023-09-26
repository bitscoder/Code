#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
vector<Node*> dfs(Node* ans, Node* node,int k){
    vector<Node*> nodeVector;
    for(auto it : node->neighbors){
        //if(k != it->val){
            cout << it -> val<< endl;
            Node* newNode = new Node(it->val);
            newNode->neighbors = dfs(newNode,it, node->val);
            nodeVector.push_back(newNode);
        //}
    }
    return nodeVector;
}
Node* cloneGraph(Node* node) {
        //vector<int> tap(101,0);
        Node* ans = new Node(node->val);
        ans->neighbors = dfs(ans, node, -1);
        return ans;   
}

