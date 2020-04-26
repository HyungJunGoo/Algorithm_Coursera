#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using pi = pair<int, int>;
bool sortbysec(const pi &a, const pi &b)
{
    return a.second < b.second;
}
struct Node
{
    int symbol; int weight;
    Node* left, *right;
};

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->weight > r->weight;
    }
};


Node* getNode(int symbol, int weight, Node* left, Node* right)
{
    Node* node = new Node();
    node->symbol = symbol;
    node->weight = weight;
    node->left = left;
    node->right = right;
    return node;
}

void encode(Node* root, string str, unordered_map<int, string> &huffmanCode )
{
    if(root == nullptr) return;
    // Found a leaf nodes
    if (!root->left && !root->right)
    {
        huffmanCode[root->symbol] = str;
    }
    encode(root->left, str+"0", huffmanCode);
    encode(root->right, str+"1", huffmanCode);
}

int main()
{
    fstream file;
    file.open("huffman.txt") ;
    int symbols_size;
    file >> symbols_size;
    priority_queue<pi, vector<pi> ,greater<pi> > pq;
    priority_queue<Node*, vector<Node*>, comp> pq_;
    int i = 1; // symbol starts from 1
    while (file.peek() != EOF)
    {
        int weights;
        file >> weights;
        pq_.push(getNode(i, weights, nullptr,nullptr));
        i++;
    }
    while (pq_.size() != 1)
    {
        Node* right = pq_.top(); pq_.pop();
        Node* left = pq_.top(); pq_.pop();
        int sum = right->weight + left->weight;
        pq_.push(getNode(-1, sum, left, right));
    }
    Node* root = pq_.top();
    unordered_map<int, string> huffmanCode;
    encode(root, "", huffmanCode);
    
    int min = 0, max = 0;
    int j = 0; 
    for (auto pair : huffmanCode)
    {
        if(j==0)
        {
            min = pair.second.length();
            max = pair.second.length();
            j++;
        }
        if( pair.second.length() < min)
            min = pair.second.length();
        if( pair.second.length() > max)
            max = pair.second.length();
    }
    cout << "min : " << min << "max : " << max << endl;

    return 0;
}