#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==0)return 0;
        Node* node_arr[110];
        for(int i=0;i<110;i++){
            node_arr[i]=0;
        }
        queue<Node*> old_queue,new_queue;
        Node* new_node=new Node(node->val);
        node_arr[new_node->val]=new_node;
        old_queue.push(node);
        new_queue.push(new_node);
        while(!old_queue.empty()){
            Node *node1=old_queue.front();
            Node *node2=new_queue.front();
            Node* current;
            for(int i=0;i<node1->neighbors.size();i++){
                if(node_arr[node1->neighbors[i]->val]==0){
                    current=new Node(node1->neighbors[i]->val);
                    node_arr[current->val]=current;
                    node2->neighbors.push_back(current);
                    old_queue.push(node1->neighbors[i]);
                    new_queue.push(current);
                }else{
                    current=node_arr[node1->neighbors[i]->val];
                    node2->neighbors.push_back(current);
                }
            }
            old_queue.pop();
            new_queue.pop();
        }
        return new_node;
    }
};