#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

struct Node {
    bool valid;
    Node* children[10];
    Node() {
        valid = false;
        for (int i=0; i<10; i++) {
            children[i] = NULL;
        }
    }
    ~Node() {
        for (int i=0; i<10; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
};
void add(Node* node, string &s, int index) {
    if (index == s.size()) {
        node->valid = true;
        return;
    }
    int c = s[index] - '0';
    if (node->children[c] == NULL) {
        node->children[c] = new Node();
    }
    add(node->children[c], s, index+1);
}
bool check(Node *node) {
    for (int i=0; i<10; i++) {
        if (node->children[i] != NULL) {
            if (node->valid == true) {
                return false;
            } else {
                if (!check(node->children[i])) {
                    return false;
                }
            }
        } 
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        vector<Node> trie;
        Node *root = new Node();
        for (int i=0; i<n; i++) {
            cin >> a[i];
            add(root, a[i], 0);
        }
        if (check(root)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}