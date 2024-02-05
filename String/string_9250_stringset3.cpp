#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://ansohxxn.github.io/algorithm/ahocorasick/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

struct Node{
    map<char, Node*> ch;
    int terminal;
    Node() : terminal(-1) {}
    ~Node() {
        for (auto &i : ch) delete i.second;
        ch.clear();
    }
    void insert(const char *key, int num) {
        if (*key == 0) {
            terminal = num; return;
        }
        if (!ch[*key]) ch[*key] = new Node();
        ch[*key]->insert(key+1, num);
    }
    Node *fail;
    vector<int> output;
};

void aho_getFail(Node* root) {
    queue<Node*> q;
    root->fail = root;
    q.push(root);
    while (q.size()) {
        Node * now = q.front(); q.pop();
        for (auto &i : now->ch) {
            Node *child = i.second;
            if (!child) continue;
            if (root == now) child->fail = root;
            else {
                Node *t = now->fail;
                while (t!=root && !t->ch[i.first]) t=t->fail;
                if (t->ch[i.first]) t = t->ch[i.first];
                child->fail = t;
            }
            child->output = child->fail->output;
            if (child->terminal != -1) {
                child->output.push(child->terminal);
            }
            q.push(child);
        }
    }
}

vector<pair<int,int>> aho_find(string &s, Node *root) {
    vector<pair<int,int>> ret;
    auto state = root;
    for (int i=0; i<s.size(); i++) {
        while(state != root && !state->ch[s[i]]) state = state->fail;
        if (state->ch[s[i]]) state = state->ch[s[i]];
        for (int j=0; j<state->output.size(); j++) {
            ret.push_back({i, state->output[j]});
        }
    }
    return ret;
}

int main() {
    int n, q, Node *root = new Node();
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        root->insert(s.c_str(), i);
    }
    aho_getFail(root);
    cin >> q;
    for (int i=0; i<q; i++) {
        string s; cin >> s;
        auto v = aho_find(s, root);
        if (v.size()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}