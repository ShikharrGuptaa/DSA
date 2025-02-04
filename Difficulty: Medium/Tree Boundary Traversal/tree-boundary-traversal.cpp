//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

class Solution {
private:
    void left_travel(Node* root, vector<int> &result){
        if (!root || (!root->left && !root->right)) return; // Ignore leaf nodes

        result.push_back(root->data);
        if (root->left) left_travel(root->left, result);
        else left_travel(root->right, result); // If no left, go right
    }
    
    void leaf_travel(Node* root, vector<int> &result){
        if (!root) return;
        
        if (!root->left && !root->right) { // Leaf node
            result.push_back(root->data);
            return;
        }
        
        leaf_travel(root->left, result);
        leaf_travel(root->right, result);
    }
    
    void rght_travel(Node* root, vector<int> &result){
        if (!root || (!root->left && !root->right)) return; // Ignore leaf nodes
        
        if (root->right) rght_travel(root->right, result);
        else rght_travel(root->left, result); // If no right, go left
        
        result.push_back(root->data); // Add after recursion to store bottom-up
    }
    
public:
    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};
        
        vector<int> result;
        result.push_back(root->data); // Add root first
        
        left_travel(root->left, result);  // Left boundary (excluding leaf nodes)
        leaf_travel(root->left, result);       // Leaf nodes
        leaf_travel(root->right, result);       // Leaf nodes
        rght_travel(root->right, result);// Right boundary (excluding leaf nodes)
        
        return result;
    }
};




//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends