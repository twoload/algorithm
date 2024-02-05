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

struct Trie{
    struct Node {
        bool valid;
        int children[10];
        Node() {
            valid = false;
            for (int i=0; i<10; i++) {
                children[i] = -1;
            }
        }
    };
    vector<Node> trie;
    int root;
    int init() {
        Node x;
        trie.push_back(x);
        return (int)trie.size()-1;
    }
    Trie() {
        root = init();
    }
    void add(int node, int num, int bit) {
        if (bit == -1) {
            trie[node].valid = true;
            return;
        }    
        int c = (num >> bit) & 1;
        if (trie[node].children[c] == -1) {
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], num, bit-1);
    }
    void add(int num) {
        add(root, num, 31);
    }
    int query(int node, int num, int bit) {
        if (bit == -1) return 0;
        int c = (num >> bit) & 1;
        c = 1-c;
        if (trie[node].children[c] == -1) {
            c = 1-c;
        }
        if (trie[node].children[c] == -1) {
            return 0;
        }
        int next = 0;
        if (c == 1) next = 1 << bit;
        return next | query(trie[node].children[c], num, bit-1);
    }
    int query(int num) {
        return query(root, num, 31);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        Trie trie;
        int prefix = 0;
        trie.add(0);
        for (int i=0; i<n; i++) {
            int num;
            cin >> num;
            prefix ^= num;
            trie.add(prefix);
            int temp = (trie.query(prefix) ^ prefix);
            if (ans < temp) ans = temp;
        }
        cout << ans << '\n';
    }
    return 0;
}
