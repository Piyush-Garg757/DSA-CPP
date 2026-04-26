#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *l, *r;
    Node(char c, int f) {
        ch = c; freq = f;
        l = r = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string s) {
    if(!root) return;
    if(!root->l && !root->r)
        cout << root->ch << " : " << s << endl;
    printCodes(root->l, s + "0");
    printCodes(root->r, s + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, cmp> pq;

    cout << "Enter characters and frequencies:\n";
    for(int i = 0; i < n; i++) {
        char c; int f;
        cin >> c >> f;
        pq.push(new Node(c, f));
    }

    while(pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *p = new Node('$', l->freq + r->freq);
        p->l = l; p->r = r;
        pq.push(p);
    }

    Node* root = pq.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");
}