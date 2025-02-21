class LRUCache {
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void delNode(Node* currNode) {
        Node* previous = currNode->prev;
        Node* forward = currNode->next;
        previous->next = forward;
        forward->prev = previous;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resultNode = mp[key];
            int ans = resultNode->value;

            delNode(resultNode);
            addNode(resultNode);

            mp[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* toDel = mp[key];
            delNode(toDel);
            mp.erase(key);
        }

        if (mp.size() >= cap) { 
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
