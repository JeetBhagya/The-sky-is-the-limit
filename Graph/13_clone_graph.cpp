#include <bits/stdc++.h>
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
class Solution {
public:
    void dfs(Node* node, Node* copy, vector<Node*>&visited)
    {
        //put copy node in visited array in the index of copy->val  
        visited[copy->val]=copy;
        
        //now go to the each neighbors node of main node, from where we make copy node 
        for(auto x: node->neighbors)
        {
            if(visited[x->val]==NULL) //not visited, so NULL
            {
                //making copy node
                Node* newNode=new Node(x->val);

                //newNOde node, make a neighbor of the copy node
                copy->neighbors.push_back(newNode);

                //repeat the task again...for x and newNode
                dfs(x, newNode, visited);
            }
            else copy->neighbors.push_back(visited[x->val]); //if visited just make a neighbor of copy node
        }
    }
    
    Node* cloneGraph(Node* node)
    {
        if(node==NULL) return NULL;


        vector<Node*>visited(1000, NULL);

        //making a copy node with node->val
        Node* copy=new Node(node->val);

        //making the whole graph using dfs 
        dfs(node, copy, visited);

        //return the clone graph node, i.e copy
        return copy;

    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    

    Solution obj;
    Node* ans=obj.cloneGraph(node);
}