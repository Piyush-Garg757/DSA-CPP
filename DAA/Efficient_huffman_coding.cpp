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

    vector<pair<char,int>> a(n);
    cout << "Enter characters and frequencies:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto &x, auto &y){
        return x.second < y.second;
    });

    queue<Node*> q1, q2;

    for(auto &x : a)
        q1.push(new Node(x.first, x.second));

    while((q1.size() + q2.size()) > 1) {
        Node *x, *y;

        if(q2.empty() || (!q1.empty() && q1.front()->freq <= q2.front()->freq)) {
            x = q1.front(); q1.pop();
        } else {
            x = q2.front(); q2.pop();
        }

        if(q2.empty() || (!q1.empty() && q1.front()->freq <= q2.front()->freq)) {
            y = q1.front(); q1.pop();
        } else {
            y = q2.front(); q2.pop();
        }

        Node* p = new Node('$', x->freq + y->freq);
        p->l = x; p->r = y;
        q2.push(p);
    }

    Node* root = q1.empty() ? q2.front() : q1.front();

    cout << "Huffman Codes:\n";
    printCodes(root, "");
}