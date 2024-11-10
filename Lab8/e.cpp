#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> prefixHashes(N);
    for (int i = 0; i < N; ++i) {
        cin >> prefixHashes[i];
    }

    string result(N, ' ');

    result[0] = static_cast<char>((prefixHashes[0] / 1) + 97);

    for (int i = 1; i < N; ++i) {
        long long diff = prefixHashes[i] - prefixHashes[i - 1];
        result[i] = static_cast<char>((diff / (1LL << i)) + 97);
    }

    cout << result << endl;

    return 0;
}
