#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;


// 0 1 2 3 
// D S L R

// 00 01 02 03
// DD DS DL DR

// 000 001 002 003
// DDD DDS DDL DDR

// 0b 01b 10b 11b
// 0000b 0001b 0010b 0011b
// 000000b 000001b 000010b 000011b


int dist[10001];
int from[10001];
char how[10001];

int move(int n, string cmd) {
    if (cmd == "D") {
        return (n*2) % 10000;
    } else if (cmd == "S") {
        if (n == 0) return 9999;
        else return n-1;
    } else if (cmd == "L") {
        return (n % 1000)*10 + n/1000;
    } else if (cmd == "R") {
        return n / 10 + (n%10)*1000;
    }
    return n;
} 

string find(int start) {
    int cur = start;
    string s;
    while (from[cur] != -1) {
        s = how[cur] + s;
        cur = from[cur];
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dist, -1, sizeof(dist));
        memset(from, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        int a = 0;
        int b = 0;
        cin >> a >> b;
        //cout << a << ", " << b << '\n';
        dist[a] = 0;
        from[a] = -1;
        how[a] = 0;
        queue<int> q;
        q.push(a);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == b) { // match => break => success!!!
                break;
            }
            int next = 0;
            // D
            next = move(cur, "D");
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'D';
                q.push(next);
            }
            // S
            next = move(cur, "S");
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'S';
                q.push(next);
            }
            // L
            next = move(cur, "L");
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'L';
                q.push(next);
            }
            // R
            next = move(cur, "R");
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'R';
                q.push(next);
            }
        } 
        //for (int i=1; i<=10; i++) {
        //    printf("dist[%d]=%d, from[%d]=%d, how[%d]=%c\n", i,dist[i],i,from[i],i,how[i]);
        //}
        //printf("a:%d, b:%d\n", a, b);
        //cout << dist[b] << '\n';
        //cout << from[b] << '\n';
        //cout << how[b] << '\n';
        cout << find(b) << '\n';
    }
    return 0;
}