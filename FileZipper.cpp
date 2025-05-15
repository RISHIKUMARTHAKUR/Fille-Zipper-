#include <bits/stdc++.h>
using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

// Compare for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traverse the Huffman tree and store codes in a map
void buildCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

// Delete tree nodes to free memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Encode input string to Huffman encoded binary string
string encode(const string& text, unordered_map<char, string>& codes) {
    string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }
    return encoded;
}

// Decode encoded binary string using Huffman tree
string decode(const string& encoded, Node* root) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    // Build priority queue (min heap) of leaf nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node(left, right);
        pq.push(merged);
    }

    Node* root = pq.top();

    // Build Huffman Codes
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (auto& p : codes) {
        cout << p.first << ": " << p.second << "\n";
    }

    // Encode
    string encoded = encode(text, codes);
    cout << "\nEncoded string:\n" << encoded << "\n";

    // Decode
    string decoded = decode(encoded, root);
    cout << "\nDecoded string:\n" << decoded << "\n";

    // Clean up memory
    deleteTree(root);

    return 0;
}
