//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

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
    int count(Node* tree){
        if(!tree) return 0;
        
        return 1 + count(tree->left) + count(tree->right);
    }
    
    bool isCBT(Node* tree, int idx, int totalNodes){
        // if leaf node: return true;
        if(!tree) return true;
        
        // If idx >= countNodes => out of bounds, false;
        if(idx >= totalNodes) return false;
        
        // Check left and right existence
        return isCBT(tree->left, 2*idx+1, totalNodes) && isCBT(tree->right, 2*(idx+1), totalNodes);
    }
    
    bool maxOrder(Node* root){
        if(!root || (!root->left && !root->right)) return true;
        if(!root->right){
            return root->data > root->left->data; 
        }
        return root->data > root->left->data && root->data > root->right->data && maxOrder(root->left) && maxOrder(root->right);
    }
    
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int totalNodes = count(tree);
        
        return isCBT(tree, 0, totalNodes) && maxOrder(tree);
        
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends