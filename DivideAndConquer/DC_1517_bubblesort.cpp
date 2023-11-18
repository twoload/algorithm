// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
long long cnt = 0;
void merge(vector<int>& a, int left, int mid, int right) {
    int n = right-left+1;
    int i=left;
    int j=mid+1;
    int k=0;
    int l=0;
    vector<int> tmp(n);
    while (i<=mid && j<=right) {
        if (a[i]<=a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            cnt += (mid-i+1);
        }
    }
    if (i>mid) {
        for(l=j;l<=right;l++) {
            tmp[k++] = a[l];
        }
    } else {
        for(l=i;l<=mid;l++) {
            tmp[k++] = a[l];
        }
    }
    for (l=left; l<=right; l++) {
        a[l] = tmp[l-left];
    }
}
void merge_sort(vector<int>& a, int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n-1);
    //for(int i=0; i<n; i++) {
    //    cout << a[i] << ' ';
    //}
    //cout << '\n';
    cout << cnt << '\n';
    return 0;
}