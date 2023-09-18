#include <bits/stdc++.h>
using namespace std;

int countPairs(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << countPairs(a, n);
    return 0;
}
