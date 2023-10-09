#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int n, m;
const int alphabet_length = 4;//26;//5;//26;

int count(int mask, vector<int>& words) {
    int cnt = 0;
    for (int i=0; i<words.size(); i++) {
        std::bitset<8> xx(mask), xxx((1<<alphabet_length)-1-mask);
        cout << "mask: " << xx << ", " << xxx << '\n';
        std::bitset<8> yy(words[i]);
        cout << "word: " << yy << '\n';
        //cout << "&[" << i << "]: " << ( words[i] & ((1<<26-1)-mask)) << '\n';
        if (( words[i] & (1<<alphabet_length)-1-mask) == 0) {
            cnt += 1;
            cout << ">> " << cnt << '\n';
        }
    }
    return cnt;
}

int go(int index, int k, int32_t mask, vector<int>& words) {
    std::bitset<4> mp(mask);
    cout << "index: " << index << ", k: " << k << ", mask: " << mp << '\n';
    int ret = 0;
    if (k < 0) { // beause index>=alphabet_length can be skipped if k <=0 : Be careful!!!
        cout << "0 (bz: k)" << '\n';
        return 0;
    }
    if (index >= alphabet_length) {
        cout << "count: " << count(mask, words) << '\n';
        return count(mask, words);
    }
    // select
    int ret1, ret2;
    ret1 = go(index+1, k-1, mask | (1<<index), words);
    if (ret < ret1) {
        ret = ret1;
    }
    // no select
    if ((index != 'a'-'a') && (index != 'n'-'a') && (index != 't'-'a') && (index != 'i'-'a') && (index != 'c'-'a')) {
        ret2 = go(index+1, k, mask, words);
        if (ret < ret2) {
            ret = ret2;
        }
    }
    cout << "ret: " << ret << '\n';
    return ret;
}

int main() {
    cin >> n >> m;
    vector<int> words(n); 
    for (int i=0; i<n; i++) {
        string s;
        int x = 0;
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            x |= (1 << (s[j] - 'a'));
        }
        words[i] = x;
    }
    cout << go(0, m, 0, words) << '\n';
    return 0;
}