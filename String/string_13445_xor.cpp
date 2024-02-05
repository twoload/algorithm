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

struct Trie {
    struct Node {
        bool valid;
        int children[2];
        int cnt[2];
        Node() {
            valid = false;
            for (int i=0; i<2; i++) {
                children[i] = -1;
                cnt[i] = 0;
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
        trie[node].cnt[c] += 1;
        add(trie[node].children[c], num, bit-1);
    }
    void add(int num) {
        add(root, num, 20);
    }
    // num = prefix = s[i]
    // s[i]   s[j]   k
    //  0      0     0
    //  0      1     1  // + all num of s[i] starting 0
    //  1      1     0
    //  1      0     1  // + all num of s[i] starting 1
    int query(int node, int num, int k, int bit) {
        if (bit == -1) return 0;
        int c1 = (k >> bit) & 1;
        int c2 = (num >> bit) & 1;
        int ans = 0;
        if (c1 == 1) {
            ans += trie[node].cnt[c2]; // s[j]
            c2 = 1-c2; // opposite bit
        }
        if (trie[node].children[c2] == -1) return ans;
        ans += query(trie[node].children[c2],num,k,bit-1);
        return ans;
    }
    int query(int num, int k) {
        return query(root, num, k, 20);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    Trie trie;
    int prefix = 0;
    trie.add(0); // ?
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        prefix ^= num;
        ans += trie.query(prefix, k);
        trie.add(prefix);
    } 
    cout << ans << '\n';
    return 0;
}