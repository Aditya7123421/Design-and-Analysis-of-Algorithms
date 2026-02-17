/*
Algorithm: Huffman Coding
Paradigm: Greedy (Min Heap)
Time Complexity: O(n log n)
Space Complexity: O(n)

Description:
Generates Huffman codes for characters
in the word "mississippi".
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    char c;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int f) {
        c = ch;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;   // Min heap
    }
};

void printCodes(Node* root, string code) {

    if(!root)
        return;

    if(root->c != '\0')
        cout << root->c << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {

    string s = "mississippi";

    unordered_map<char, int> freq;

    for(char c : s)
        freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for(auto pair : freq)
        minHeap.push(new Node(pair.first, pair.second));

    while(minHeap.size() > 1) {

        Node* first = minHeap.top(); minHeap.pop();
        Node* second = minHeap.top(); minHeap.pop();

        Node* merged = new Node('\0',
                                first->freq + second->freq);

        merged->left = first;
        merged->right = second;

        minHeap.push(merged);
    }

    Node* root = minHeap.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}
