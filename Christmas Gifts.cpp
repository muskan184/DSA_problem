#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int T;
    cin >> T; // Read number of test cases
    while (T--) {
        int H, L, W;
        cin >> H >> L >> W;

        int area = 2 * (H * L + H * W + L * W);

        int max_gifts = 1000 / area;
        
        cout << max_gifts << endl; // Output result
    }

    return 0;
}
