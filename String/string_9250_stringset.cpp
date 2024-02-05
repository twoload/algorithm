#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

struct Trie {
    bool isEnd;
    Trie* node[26];
    Trie* fail;

    Trie() {
        for (int i=0; i<26; i++) node[i] = NULL;
        fail = NULL;
    }

    void insert(string& str, int idx) {
        if (idx == str.size()) {
            return;
        }
        int curr = str[idx]-'a'; 
        if (node[curr] == NULL) {
            node[curr] = new Trie();
        }
        node[curr]->insert(str, idx+1);
    }

    bool find(string& str, int idx) {
        if (idx == str.size()) {
            return true;
        }
        int curr = str[idx]-'a';
        if (node[curr] == NULL) {
            return false;
        }
        return node[curr]->find(str, idx+1);
    }

    void fail() {
        Trie* root = this;
        queue<Trie*> q;

        q.push(root);

        while (!q.empty()) {
            Trie* now = q.front();
            q.pop();

            for (auto& ch : now->node)
        }
    }
};