// A2: Huffman Encoding using a greedy strategy (always merge the two least-frequent nodes)
// Time O(n log n) for n distinct characters, Space O(n)
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f, Node* l = nullptr, Node* r = nullptr) : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {  // makes priority_queue a min-heap on frequency
    bool operator()(Node* a, Node* b) { 
        return a->freq > b->freq; 
    }
};

void buildCodes(Node* root, string code, map<char, string>& codes) {
    if (!root->left && !root->right) {  // leaf = a real character
        codes[root->ch] = code.empty() ? "0" : code;
        return;
    }
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    cout << "\nMerging (greedy):" << endl;
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        cout << left->freq << " + " << right->freq << " = " << left->freq + right->freq << endl;
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    map<char, string> codes;
    buildCodes(pq.top(), "", codes);

    cout << "\nChar  Freq  Code" << endl;
    for (auto p : codes)
        cout << "'" << p.first << "'   " << freq[p.first] << "     " << p.second << endl;

    string encoded;
    for (char c : text)
        encoded += codes[c];
    cout << "\nEncoded: " << encoded << endl;
    cout << "Bits: " << encoded.size() << " (Huffman) vs " << text.size() * 8 << " (8-bit ASCII)" << endl;
    return 0;
}
